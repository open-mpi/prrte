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
# Copyright (c) 2006      Sun Microsystems, Inc.  All rights reserved.
#                         Use is subject to license terms.
# Copyright (c) 2010-2020 Cisco Systems, Inc.  All rights reserved
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# Copyright (c) 2017-2020 Intel, Inc.  All rights reserved.
# Copyright (c) 2022-2025 Nanook Consulting  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

EXTRA_DIST = help-ras-gridengine.txt

sources = \
        ras_gridengine.h \
        ras_gridengine_component.c \
        ras_gridengine_module.c

# Make the output library in this directory, and name it either
# mca_<type>_<name>.la (for DSO builds) or libmca_<type>_<name>.la
# (for static builds).

if MCA_BUILD_prte_ras_gridengine_DSO
component_noinst =
component_install = prte_mca_ras_gridengine.la
else
component_noinst = libprtemca_ras_gridengine.la
component_install =
endif

mcacomponentdir = $(prtelibdir)
mcacomponent_LTLIBRARIES = $(component_install)
prte_mca_ras_gridengine_la_SOURCES = $(sources)
prte_mca_ras_gridengine_la_LDFLAGS = -module -avoid-version
prte_mca_ras_gridengine_la_LIBADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

noinst_LTLIBRARIES = $(component_noinst)
libprtemca_ras_gridengine_la_SOURCES =$(sources)
libprtemca_ras_gridengine_la_LDFLAGS = -module -avoid-version
