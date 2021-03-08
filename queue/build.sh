#!/bin/bash
gcc -o list.o -c list.c 
gcc -o queue.o -c queue.c
gcc test.c queue.o list.o
find list.o queue.o a.out
 

 

