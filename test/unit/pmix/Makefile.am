# $COPYRIGHT$
# Additional copyrights may follow
# $HEADER$

AM_CPPFLAGS = \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/include \
    -I$(top_srcdir)

check_PROGRAMS = test_pmix

test_pmix_SOURCES = \
    test_pmix.c

test_pmix_LDADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

TESTS = test_pmix
