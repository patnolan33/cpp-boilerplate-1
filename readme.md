# C++ Boilerplate
[![Build Status](https://travis-ci.org/ShaotuJia/cpp-boilerplate.svg?branch=master)](https://travis-ci.org/ShaotuJia/cpp-boilerplate)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/cpp-boilerplate?branch=master)
---

## Overview

PID controller project with:

- cmake
- googletest

UML_Diagram: 

- Activity Diagram
- Class Diagram

## Installation

- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/dpiet/cpp-boilerplate.git
```
## Run Project

- Build project using cmake
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
- Run program
```
$ ./app/shell-app
```
- Run test
```
$ ./test/cpp-test
```

## NOTES:
- After collaboration, the original design was modified to give more flexibility for implementers to see the output of the compute method by adding "getters" for the set point and actual velocity
- The tests were modified accordingly to the design modifications

## TODO:
- Change the design to make better use of the setPoint and actualVelocity member variables
	- If we are going to use member variables, a better design may be to add "set" methods to allow implementers a way to change the setPoints and even the actual velocity. This way, the compute method would take no inputs and rely on the state of the member variables

## Additional Tests to add:
- Checking for proper initialization of gains from constructor
- Checking for negative velocities supplied to the compute() method
- Checking whether or not the system settled
	- If gains are set improperly and the system is unstable, then we won't ever converge close enough to the set point and the loop will break out to avoid locking up
	- We should check this case, i.e. when the actual velocity is null or nan, then we know the system did not settle

