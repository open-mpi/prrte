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
# Copyright (c) 2010-2020 Cisco Systems, Inc.  All rights reserved
# Copyright (c) 2017-2020 Intel, Inc.  All rights reserved.
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# Copyright (c) 2022-2025 Nanook Consulting  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

EXTRA_DIST = \
        help-prte-rmaps-rr.txt

sources = \
        rmaps_rr.c \
        rmaps_rr.h \
        rmaps_rr_component.c \
        rmaps_rr_mappers.c

# Make the output library in this directory, and name it either
# mca_<type>_<name>.la (for DSO builds) or libmca_<type>_<name>.la
# (for static builds).

if MCA_BUILD_prte_rmaps_round_robin_DSO
component_noinst =
component_install = prte_mca_rmaps_round_robin.la
else
component_noinst = libprtemca_rmaps_round_robin.la
component_install =
endif

mcacomponentdir = $(prtelibdir)
mcacomponent_LTLIBRARIES = $(component_install)
prte_mca_rmaps_round_robin_la_SOURCES = $(sources)
prte_mca_rmaps_round_robin_la_LDFLAGS = -module -avoid-version
prte_mca_rmaps_round_robin_la_LIBADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

noinst_LTLIBRARIES = $(component_noinst)
libprtemca_rmaps_round_robin_la_SOURCES =$(sources)
libprtemca_rmaps_round_robin_la_LDFLAGS = -module -avoid-version
