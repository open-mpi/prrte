# This is an Open MPI fork of the PRRTE v3.0 branch

This fork is meant to be used in the OMPI v5.0.x branch; it's a
mechanism to pull upstream PRRTE commits and also maintain any Open
MPI-specific patches on top of that.

Specifically: this branch is expected to be regularly updated to bring
support from the upstream PRRTE to match the needs of the Open MPI
v5.0.x branch.

# PMIx Reference RunTime Environment (PRRTE)

PRRTE is [the PMIx Reference RunTime
Environment](https://github.com/openpmix/prrte)

## Official documentation

The PRRTE documentation can be viewed in the following ways:

1. Online at https://docs.prrte.org/
1. In self-contained (i.e., suitable for local viewing, without an
   internet connection) in official distribution tarballs under
   `docs/_build/html/index.html`.

## Building the documentation locally

The source code for PRRTE's docs can be found in the PRRTE Git
repository under the `docs` folder.

Developers who clone the PRRTE Git repository will not have the
HTML documentation and man pages by default; it must be built.
Instructions for how to build the PRRTE documentation can be found
here:
https://docs.prrte.org/en/latest/developers/sphinx.html
