#!/bin/bash
gcc -o clist.o -c clist.c
gcc test.c clist.o
ls -l | grep clist.o & ls -l | grep a.out
 

 

