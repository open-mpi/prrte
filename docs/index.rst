Open MPI's fork of the PMIx Runtime Environment (PRRTE) |prte_ver|
==================================================================

.. important:: This copy of the PRRTE software is not the official
               upstream community version, but instead is a fork used
               internally by the Open MPI project for its v5.0.x
               stable series.  If there are any questions or concerns,
               or to report bugs and issues, please contact the Open
               MPI community.  More information available at
               https://github.com/open-mpi/prrte

The remainder of this documentation mirrors the official PRRTE
documentation.


PMIx Reference Runtime Environment (PRRTE) |prte_ver|
=====================================================

The project is formally referred to in documentation by "PRRTE", and
the GitHub repository is ``prrte``.

.. note:: We have found that most users do not like typing the two
          consecutive ``r`` letters in the name. Hence, all of the
          internal API symbols, environment variables, MCA frameworks,
          and CLI executables all use the abbreviated ``prte`` (one
          ``r``, not two) for convenience.

Documentation locations
=======================

This documentation can be found in the following locations:

* On the web: https://docs.prrte.org/
* In the tarball: ``docs/_build/html/index.html``
* Installed: ``$prefix/share/doc/prrte/html/index.html``

Table of contents
=================

.. toctree::
   :maxdepth: 2
   :numbered:

   quickstart
   release-notes
   getting-help
   install
   configuration
   how-things-work/index
   hosts/index
   placement/index
   notifications
   session-directory
   developers/index
   contributing
   license
   man/index
   versions
   news/index
