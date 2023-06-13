#!/bin/bash

echo "Compile script ...";

g++ -c main.cpp;
g++ -c Game.cpp;

g++ -Wall -O2 -o main main.o Game.o;


echo "Script complete ...";
