#
# Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
#                         University Research and Technology
#                         Corporation.  All rights reserved.
# Copyright (c) 2004-2005 The University of Tennessee and The University
#                         of Tennessee Research Foundation.  All rights
#                         reserved.
# Copyright (c) 2004-2009 High Performance Computing Center Stuttgart,
#                         University of Stuttgart.  All rights reserved.
# Copyright (c) 2004-2005 The Regents of the University of California.
#                         All rights reserved.
# Copyright (c) 2007-2020 Cisco Systems, Inc.  All rights reserved
# Copyright (c) 2008      Sun Microsystems, Inc.  All rights reserved.
# Copyright (c) 2016-2020 Intel, Inc.  All rights reserved.
# Copyright (c) 2021-2025 Nanook Consulting  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#


AM_LDFLAGS = $(prte_hwloc_LDFLAGS) $(prte_libevent_LDFLAGS) $(prte_pmix_LDFLAGS)
AM_CFLAGS = \
            -DPRTE_CONFIGURE_USER="\"@PRTE_CONFIGURE_USER@\"" \
            -DPRTE_CONFIGURE_HOST="\"@PRTE_CONFIGURE_HOST@\"" \
            -DPRTE_CONFIGURE_DATE="\"@PRTE_CONFIGURE_DATE@\"" \
            -DPRTE_BUILD_USER="\"$$USER\"" \
            -DPRTE_BUILD_HOST="\"$${HOSTNAME:-`(hostname || uname -n) | sed 1q`}\"" \
            -DPRTE_BUILD_DATE="\"`$(top_srcdir)/config/getdate.sh`\"" \
            -DPRTE_BUILD_CFLAGS="\"@CFLAGS@\"" \
            -DPRTE_BUILD_CPPFLAGS="\"@CPPFLAGS@\"" \
            -DPRTE_BUILD_LDFLAGS="\"@LDFLAGS@\"" \
            -DPRTE_BUILD_LIBS="\"@LIBS@\"" \
            -DPRTE_CC_ABSOLUTE="\"@PRTE_CC_ABSOLUTE@\"" \
            -DPRTE_GREEK_VERSION="\"@PRTE_GREEK_VERSION@\"" \
            -DPRTE_REPO_REV="\"@PRTE_REPO_REV@\"" \
            -DPMIX_RELEASE_DATE="\"@PMIX_RELEASE_DATE@\""

bin_PROGRAMS = @PRTE_BINARY_PREFIX@prted

@PRTE_BINARY_PREFIX@prted_SOURCES = prted.c
# the following empty prted_LDFLAGS is used
#  so that the prted can be compiled statically
#  by simply changing the value of this from
#  nothing to -all-static in the Makefile.in
#  nice for systems that don't have all the shared
#  libraries on the computes
@PRTE_BINARY_PREFIX@prted_LDFLAGS =
@PRTE_BINARY_PREFIX@prted_LDADD = \
    $(prte_libevent_LIBS) \
    $(prte_hwloc_LIBS) \
    $(prte_pmix_LIBS) \
	$(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la
