# $COPYRIGHT$
# Additional copyrights may follow
# $HEADER$

AM_CPPFLAGS = \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/include \
    -I$(top_srcdir)

check_PROGRAMS = test_include

test_include_SOURCES = \
    test_include.c

test_include_LDADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

TESTS = test_include
