# $COPYRIGHT$
# Additional copyrights may follow
# $HEADER$

AM_CPPFLAGS = \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/include \
    -I$(top_srcdir)

check_PROGRAMS = test_hwloc

test_hwloc_SOURCES = \
    test_hwloc.c

test_hwloc_LDADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

TESTS = test_hwloc
