#!/bin/bash
gcc -o list.o -c list.c 
gcc -o stack.o -c stack.c
gcc test.c stack.o list.o
find list.o stack.o a.out
 

 

