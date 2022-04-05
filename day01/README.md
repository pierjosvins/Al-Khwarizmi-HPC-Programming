<h1 align="center" style="color:blue;"> Envirenment Preparation</h1>

For avoiding problems in installation, try to follow the order of installation, contact us for any problem or complexity you encounter.

## Install gcc for C language

*GCC* stands for *GNU Compiler Collections* which is used to compile mainly *C* and *C++* language. It can also be used to compile *Objective C* and *Objective C++*. The *GCC* is an open-source collection of compilers and libraries.

Open your terminal and run the following commands, each command associated with a description:

- `sudo apt-get update` for updating the existing packages in your system.
- `sudo apt install build-essential` to install the build-essential packages, which is also known as a meta-package, it contains the GCC compiler all the other essentials used to compile the software written in C and C++ language.
- `gcc --version` you will get the version of the gcc installed on success.

## Install gfortran for Fortran language
GNU Fortran or GFortran is the GNU Fortran compiler, which is part of the GNU Compiler Collection (GCC). It includes full support for the Fortran 95 language, and supports large parts of the Fortran 2003 and Fortran 2008 standards

Open your terminal and run the following commands:

- `sudo apt install gfortran` for installing gfortran compiler
- `gfortran --version` to make sure gfortran is installed. this command output the version of the gfortran installed on your system.

## Installing of additional packages for Linear algebra
#### Blas and Lapack
*BLAS* (Basic Linear Algebra Subprogram and *LAPACK* (Linear Algebra PACK) are two of the most commonly used libraries in advanced research computing. They are used for vector and matrix operations that are commonly found in a plethora of algorithms.

To install both Blas & Lapack run this command `sudo apt install libblas-dev liblapack-dev`
#### Open MPI
*MPI* is a standard library for performing parallel processing using a distributed memory model. *OpenMPI* is one implementation of the *MPI* spec and they do support the latest `3.1` spec. There are many other implementations of *MPI* such as *MVAPICH*, *MPICH*, and *IntelMPI*

To install run this command `sudo apt install libopenmpi-dev openmpi-bin`

## Python prepare envirenment

#### Installing Python

Most factory versions of Ubuntu 18.04 or Ubuntu 20.04 come with Python pre-installed. Check your version of Python by entering the following: `python --version`.

If the revision level is lower than 3.7.x, or if Python is not installed, run the following commands.
- `sudo apt update` Update and Refresh Repository Lists.
- `sudo apt install software-properties-common`  Install Supporting Software
- `sudo add-apt-repository ppa:deadsnakes/ppa` Add Deadsnakes PPA
- `sudo apt update` Refresh the package lists again.
- `sudo apt install python3.8` install python version 3.8
- `python3 --version` to verify that python is installed.

#### Install python packages
