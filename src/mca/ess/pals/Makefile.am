#
# Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
#                         University Research and Technology
#                         Corporation.  All rights reserved.
# Copyright (c) 2004-2005 The University of Tennessee and The University
#                         of Tennessee Research Foundation.  All rights
#                         reserved.
# Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
#                         University of Stuttgart.  All rights reserved.
# Copyright (c) 2004-2005 The Regents of the University of California.
#                         All rights reserved.
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# Copyright (c) 2017-2020 Intel, Inc.  All rights reserved.
# Copyright (c) 2020      Cisco Systems, Inc.  All rights reserved
# Copyright (c) 2022      Nanook Consulting.  All rights reserved.
# Copyright (c) 2023      Triad National Security, LLC. All rights
#                         reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

sources = \
        ess_pals.h \
        ess_pals_component.c \
        ess_pals_module.c

# Make the output library in this directory, and name it either
# mca_<type>_<name>.la (for DSO builds) or libmca_<type>_<name>.la
# (for static builds).

if MCA_BUILD_prte_ess_pals_DSO
component_noinst =
component_install = prte_mca_ess_pals.la
else
component_noinst = libprtemca_ess_pals.la
component_install =
endif

mcacomponentdir = $(prtelibdir)
mcacomponent_LTLIBRARIES = $(component_install)
prte_mca_ess_pals_la_SOURCES = $(sources)
prte_mca_ess_pals_la_LDFLAGS = -module -avoid-version
prte_mca_ess_pals_la_LIBADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

noinst_LTLIBRARIES = $(component_noinst)
libprtemca_ess_pals_la_SOURCES =$(sources)
libprtemca_ess_pals_la_LDFLAGS = -module -avoid-version
