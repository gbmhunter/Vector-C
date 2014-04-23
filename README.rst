==================================================================
vector-c
==================================================================

--------------------------------------------------------------------
A vector container (similar to C++'s std::vector) for C programming.
--------------------------------------------------------------------

.. image:: https://api.travis-ci.org/gbmhunter/vector-c.png?branch=master   
	:target: https://travis-ci.org/gbmhunter/vector-c

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- Created: 2014/04/22
- Last Modified: 2014/04/23
- Version: v0.3.0.0
- Company: CladLabs
- Project: Free Code Libraries
- Language: C
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

.. role:: bash(code)
	:language: bash

Description
===========






Portable (Platform Agnostic)
----------------------------




Easy Including
--------------






Included Unit Tests
-------------------




Installation
============

1. Clone the git repo onto your local storage.

2. Run :code:`make all` to compile and run unit tests. Do not worry about error messages being printed when unit tests are run, the unit tests are designed to specifically cause errors to test the response.

3. To include CsvCpp into your embedded (or otherwise) firmware/software project, copy the repo into your project folder (or other suitable place) and include the file :code:`/api/CsvCpp.hpp` from your C++ code.


Dependencies
============

The following table lists all of the dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================

====================== ==================== ======================================================================


Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet!

Usage
=====

Nothing here yet!
	
	
FAQ
===

Nothing yet...

Changelog
=========

========= ========== ===================================================================================================
Version    Date       Comment
========= ========== ===================================================================================================
v0.3.0.0  2014/04/23 Unit test library compiling and linking correctly in project Makefile.
v0.2.0.0  2014/04/23 Added cpputest as a git submodule to 'lib/cpputest'.
v0.1.0.0  2014/04/23 Initial commit. Vector.c and Vector.h are present but havn't been tested yet. README needs updating.
========= ========== ===================================================================================================