#!/bin/bash
gcc -fpic -c push.c main.c pall.c
gcc -shared -o libmonty.so push.o pall.o
gcc main.o -L. -lmonty -o main1
#LD_LIBRARY_PATH=/data/data/com.termux/files/home/monty/Extra:${LD_LIBRARY_PATH}
#export LD_LIBRARY_PATH
rm *.o
echo $LD_LIBRARY_PATH
ldd main1

