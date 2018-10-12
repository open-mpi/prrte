/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2014 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2006      Los Alamos National Security, LLC.  All rights
 *                         reserved.
 * Copyright (c) 2008-2015 Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2009      Oak Ridge National Labs.  All rights reserved.
 * Copyright (c) 2010-2014 Los Alamos National Security, LLC.
 *                         All rights reserved.
 * Copyright (c) 2014      Hochschule Esslingen.  All rights reserved.
 * Copyright (c) 2015      Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * Copyright (c) 2015      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * Copyright (c) 2017      IBM Corporation.  All rights reserved.
 * Copyright (c) 2017-2018 Intel, Inc. All rights reserved.
 * Copyright (c) 2018      Amazon.com, Inc. or its affiliates.  All Rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "opal_config.h"

#include <time.h>
#include <signal.h>

#include "opal/constants.h"
#include "opal/runtime/opal.h"
#include "opal/mca/base/mca_base_var.h"
#include "opal/threads/mutex.h"
#include "opal/threads/threads.h"
#include "opal/mca/base/mca_base_var.h"
#include "opal/runtime/opal_params.h"
#include "opal/dss/dss.h"
#include "opal/util/opal_environ.h"
#include "opal/util/show_help.h"
#include "opal/util/timings.h"
#include "opal/util/printf.h"

char *opal_signal_string = NULL;
char *opal_stacktrace_output_filename = NULL;
char *opal_net_private_ipv4 = NULL;
char *opal_set_max_sys_limits = NULL;

#if OPAL_ENABLE_TIMING
char *opal_timing_sync_file = NULL;
char *opal_timing_output = NULL;
bool opal_timing_overhead = true;
#endif

int opal_abort_delay = 0;
bool opal_abort_print_stack = false;
int opal_pmix_verbose_output = 0;

static bool opal_register_done = false;

int opal_register_params(void)
{
    int ret;
    char *string = NULL;

    if (opal_register_done) {
        return OPAL_SUCCESS;
    }

    opal_register_done = true;

    /*
     * This string is going to be used in opal/util/stacktrace.c
     */
    {
        int j;
        int signals[] = {
#ifdef SIGABRT
            SIGABRT,
#endif
#ifdef SIGBUS
            SIGBUS,
#endif
#ifdef SIGFPE
            SIGFPE,
#endif
#ifdef SIGSEGV
            SIGSEGV,
#endif
            -1
        };
        for (j = 0 ; signals[j] != -1 ; ++j) {
            if (j == 0) {
                opal_asprintf(&string, "%d", signals[j]);
            } else {
                char *tmp;
                opal_asprintf(&tmp, "%s,%d", string, signals[j]);
                free(string);
                string = tmp;
            }
        }

        opal_signal_string = string;
        ret = mca_base_var_register ("opal", "opal", NULL, "signal",
                                     "Comma-delimited list of integer signal numbers to Open MPI to attempt to intercept.  Upon receipt of the intercepted signal, Open MPI will display a stack trace and abort.  Open MPI will *not* replace signals if handlers are already installed by the time MPI_INIT is invoked.  Optionally append \":complain\" to any signal number in the comma-delimited list to make Open MPI complain if it detects another signal handler (and therefore does not insert its own).",
                                     MCA_BASE_VAR_TYPE_STRING, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                     OPAL_INFO_LVL_3, MCA_BASE_VAR_SCOPE_LOCAL,
                                     &opal_signal_string);
        free (string);
        if (0 > ret) {
            return ret;
        }
    }

    /*
     * Where should the stack trace output be directed
     * This string is going to be used in opal/util/stacktrace.c
     */
    string = strdup("stderr");
    opal_stacktrace_output_filename = string;
    ret = mca_base_var_register ("opal", "opal", NULL, "stacktrace_output",
                                 "Specifies where the stack trace output stream goes.  "
                                 "Accepts one of the following: none (disabled), stderr (default), stdout, file[:filename].   "
                                 "If 'filename' is not specified, a default filename of 'stacktrace' is used.  "
                                 "The 'filename' is appended with either '.PID' or '.RANK.PID', if RANK is available.  "
                                 "The 'filename' can be an absolute path or a relative path to the current working directory.",
                                 MCA_BASE_VAR_TYPE_STRING, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_3,
                                 MCA_BASE_VAR_SCOPE_LOCAL,
                                 &opal_stacktrace_output_filename);
    free (string);
    if (0 > ret) {
        return ret;
    }


#if defined(HAVE_SCHED_YIELD)
    opal_progress_yield_when_idle = false;
    ret = mca_base_var_register ("opal", "opal", "progress", "yield_when_idle",
                                 "Yield the processor when waiting on progress",
                                 MCA_BASE_VAR_TYPE_BOOL, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_8, MCA_BASE_VAR_SCOPE_LOCAL,
                                 &opal_progress_yield_when_idle);
#endif

#if OPAL_ENABLE_DEBUG
    opal_progress_debug = false;
    ret = mca_base_var_register ("opal", "opal", "progress", "debug",
                                 "Set to non-zero to debug progress engine features",
                                 MCA_BASE_VAR_TYPE_BOOL, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_8, MCA_BASE_VAR_SCOPE_LOCAL,
                                 &opal_progress_debug);
    if (0 > ret) {
        return ret;
    }

    opal_debug_threads = false;
    ret = mca_base_var_register ("opal", "opal", "debug", "threads",
                                 "Debug thread usage within OPAL. Reports out "
                                 "when threads are acquired and released.",
                                 MCA_BASE_VAR_TYPE_BOOL, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_8, MCA_BASE_VAR_SCOPE_LOCAL,
                                 &opal_debug_threads);
    if (0 > ret) {
        return ret;
    }
#endif

    /* RFC1918 defines
       - 10.0.0./8
       - 172.16.0.0/12
       - 192.168.0.0/16

       RFC3330 also mentions
       - 169.254.0.0/16 for DHCP onlink iff there's no DHCP server
    */
    opal_net_private_ipv4 = "10.0.0.0/8;172.16.0.0/12;192.168.0.0/16;169.254.0.0/16";
    ret = mca_base_var_register ("opal", "opal", "net", "private_ipv4",
                                 "Semicolon-delimited list of CIDR notation entries specifying what networks are considered \"private\" (default value based on RFC1918 and RFC3330)",
                                 MCA_BASE_VAR_TYPE_STRING, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_3, MCA_BASE_VAR_SCOPE_ALL_EQ,
                                 &opal_net_private_ipv4);
    if (0 > ret) {
        return ret;
    }

    opal_set_max_sys_limits = NULL;
    ret = mca_base_var_register ("opal", "opal", NULL, "set_max_sys_limits",
                                 "Set the specified system-imposed limits to the specified value, including \"unlimited\"."
                                 "Supported params: core, filesize, maxmem, openfiles, stacksize, maxchildren",
                                 MCA_BASE_VAR_TYPE_STRING, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
                                 OPAL_INFO_LVL_3, MCA_BASE_VAR_SCOPE_ALL_EQ,
                                 &opal_set_max_sys_limits);
    if (0 > ret) {
        return ret;
    }

    opal_abort_delay = 0;
    ret = mca_base_var_register("opal", "opal", NULL, "abort_delay",
                                "If nonzero, print out an identifying message when abort operation is invoked (hostname, PID of the process that called abort) and delay for that many seconds before exiting (a negative delay value means to never abort).  This allows attaching of a debugger before quitting the job.",
                                 MCA_BASE_VAR_TYPE_INT, NULL, 0, 0,
                                 OPAL_INFO_LVL_5,
                                 MCA_BASE_VAR_SCOPE_READONLY,
                                 &opal_abort_delay);
    if (0 > ret) {
        return ret;
    }

    opal_abort_print_stack = false;
    ret = mca_base_var_register("opal", "opal", NULL, "abort_print_stack",
                                 "If nonzero, print out a stack trace when abort is invoked",
                                 MCA_BASE_VAR_TYPE_BOOL, NULL, 0,
                                /* If we do not have stack trace
                                   capability, make this a constant
                                   MCA variable */
#if OPAL_WANT_PRETTY_PRINT_STACKTRACE
                                 0,
                                 OPAL_INFO_LVL_5,
                                 MCA_BASE_VAR_SCOPE_READONLY,
#else
                                 MCA_BASE_VAR_FLAG_DEFAULT_ONLY,
                                 OPAL_INFO_LVL_5,
                                 MCA_BASE_VAR_SCOPE_CONSTANT,
#endif
                                 &opal_abort_print_stack);
    if (0 > ret) {
        return ret;
    }

    /* register the envar-forwarding params */
    (void)mca_base_var_register ("opal", "mca", "base", "env_list",
                                 "Set SHELL env variables",
                                 MCA_BASE_VAR_TYPE_STRING, NULL, 0, 0, OPAL_INFO_LVL_3,
                                 MCA_BASE_VAR_SCOPE_READONLY, &mca_base_env_list);

    mca_base_env_list_sep = MCA_BASE_ENV_LIST_SEP_DEFAULT;
    (void)mca_base_var_register ("opal", "mca", "base", "env_list_delimiter",
                                 "Set SHELL env variables delimiter. Default: semicolon ';'",
                                 MCA_BASE_VAR_TYPE_STRING, NULL, 0, 0, OPAL_INFO_LVL_3,
                                 MCA_BASE_VAR_SCOPE_READONLY, &mca_base_env_list_sep);

    /* Set OMPI_MCA_mca_base_env_list variable, it might not be set before
     * if mca variable was taken from amca conf file. Need to set it
     * here because mca_base_var_process_env_list is called from schizo_ompi.c
     * only when this env variable was set.
     */
    if (NULL != mca_base_env_list) {
        char *name = NULL;
        (void) mca_base_var_env_name ("mca_base_env_list", &name);
        if (NULL != name) {
            opal_setenv(name, mca_base_env_list, false, &environ);
            free(name);
        }
    }

    /* Register internal MCA variable mca_base_env_list_internal. It can be set only during
     * parsing of amca conf file and contains SHELL env variables specified via -x there.
     * Its format is the same as for mca_base_env_list.
     */
    (void)mca_base_var_register ("opal", "mca", "base", "env_list_internal",
            "Store SHELL env variables from amca conf file",
            MCA_BASE_VAR_TYPE_STRING, NULL, 0, MCA_BASE_VAR_FLAG_INTERNAL, OPAL_INFO_LVL_3,
            MCA_BASE_VAR_SCOPE_READONLY, &mca_base_env_list_internal);

    /* dss has parameters */
    ret = opal_dss_register_vars ();
    if (OPAL_SUCCESS != ret) {
        return ret;
    }

    mca_base_var_register("opal", "opal", NULL, "pmix_verbose",
                          "Verbosity for OPAL-level PMIx code",
                          MCA_BASE_VAR_TYPE_INT, NULL, 0, 0,
                          OPAL_INFO_LVL_5,
                          MCA_BASE_VAR_SCOPE_READONLY,
                          &opal_pmix_verbose_output);

    return OPAL_SUCCESS;
}

int opal_deregister_params(void)
{
    opal_register_done = false;

    return OPAL_SUCCESS;
}
