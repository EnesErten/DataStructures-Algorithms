#!/bin/bash
gcc -o dlist.o -c dlist.c
gcc test.c dlist.o
ls -l | grep dlist.o & ls -l | grep a.out


 

