# HW 5: Dijkstra

***

DCS-229A: Data Structures and Algorithms
Aru Poleo Vargas
Prof. Barry Lawson

***

## WHAT

An implementation of Dijkstra's Algorithm for path finding written in Modern C++.

The project will generate two binaries.

tests: The testing, built using Google's GoogleTest library.
main: Interactable CLI to play around with one Adjacency Matrix.

## HOW TO COMPILE

The project uses CMake as a build tool. A makefile is provided in the build 
directory, but it can be generated again by running the following from the build 
directory:

	cmake ..

For compilation, from the build directory run:

	make 
	
Binaries for your system will be generated in the bin directory, also inside build.

This project makes use of C++20 features, namely views and ranges, so updating your compiler
is strongly adviced before building.

