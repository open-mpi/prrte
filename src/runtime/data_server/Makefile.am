# -*- makefile -*-
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
# Copyright (c) 2010-2020 Cisco Systems, Inc.  All rights reserved
# Copyright (c) 2014-2020 Intel, Inc.  All rights reserved.
# Copyright (c) 2021-2025 Nanook Consulting  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

# This makefile.am does not stand on its own - it is included from src/runtime/Makefile.am

headers += \
        runtime/data_server/prte_data_server.h \
        runtime/data_server/ds.h

lib@PRTE_BINARY_PREFIX@prrte_la_SOURCES += \
        runtime/data_server/ds_main.c \
        runtime/data_server/ds_publish.c \
        runtime/data_server/ds_lookup.c \
        runtime/data_server/ds_unpublish.c \
        runtime/data_server/ds_purge.c
