#!/bin/bash
gcc -o list.o -c list.c
gcc test.c list.o
ls -l | grep list.o & ls -l | grep a.out
 

 

