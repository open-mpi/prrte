#
# Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
#                         University Research and Technology
#                         Corporation.  All rights reserved.
# Copyright (c) 2004-2008 The University of Tennessee and The University
#                         of Tennessee Research Foundation.  All rights
#                         reserved.
# Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
#                         University of Stuttgart.  All rights reserved.
# Copyright (c) 2004-2005 The Regents of the University of California.
#                         All rights reserved.
# Copyright (c) 2007-2020 Cisco Systems, Inc.  All rights reserved
# Copyright (c) 2008      Institut National de Recherche en Informatique
#                         et Automatique. All rights reserved.
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# Copyright (c) 2017-2020 Intel, Inc.  All rights reserved.
# Copyright (c) 2022-2025 Nanook Consulting  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

AM_CPPFLAGS = $(plm_lsf_CPPFLAGS)

EXTRA_DIST = \
        help-plm-lsf.txt \
        testbuild_lsf.h

sources = \
        plm_lsf.h \
        plm_lsf_component.c \
        plm_lsf_module.c

# Make the output library in this directory, and name it either
# mca_<type>_<name>.la (for DSO builds) or libmca_<type>_<name>.la
# (for static builds).

if MCA_BUILD_prte_plm_lsf_DSO
component_noinst =
component_install = prte_mca_plm_lsf.la
else
component_noinst = libprtemca_plm_lsf.la
component_install =
endif

mcacomponentdir = $(prtelibdir)
mcacomponent_LTLIBRARIES = $(component_install)
prte_mca_plm_lsf_la_SOURCES = $(sources)
prte_mca_plm_lsf_la_LDFLAGS = -module -avoid-version $(plm_lsf_LDFLAGS)
prte_mca_plm_lsf_la_LIBADD = $(plm_lsf_LIBS) \
                        $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

noinst_LTLIBRARIES = $(component_noinst)
libprtemca_plm_lsf_la_SOURCES = $(sources)
libprtemca_plm_lsf_la_LDFLAGS = -module -avoid-version $(plm_lsf_LDFLAGS)
libprtemca_plm_lsf_la_LIBADD = $(plm_lsf_LIBS)
