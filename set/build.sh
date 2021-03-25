#!/bin/bash
gcc -o list.o -c list.c  
gcc -o set.o -c set.c
gcc test.c set.o list.o
find list.o set.o a.out
 

 

