# $COPYRIGHT$
# Additional copyrights may follow
# $HEADER$

AM_CPPFLAGS = \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/include \
    -I$(top_srcdir)

check_PROGRAMS = test_event

test_event_SOURCES = \
    test_event.c

test_event_LDADD = $(top_builddir)/src/lib@PRTE_BINARY_PREFIX@prrte.la

TESTS = test_event
