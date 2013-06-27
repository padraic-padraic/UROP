#!/bin/sh
echo "Moving in."
cd /home/padraic/Projects/UROP
echo "Cleaning up"
rm ./Infection
rm ./Infection.o
echo "Step 1"
g++ -c -g -O3 ./Infection.cpp -I /usr/local/include
echo "Step 2"
g++ -g -o Infection Infection.o -L /usr/local/lib -l Random
echo "Step 3"
g++ -g -o Infection Infection.o -Wl,-rpath=/usr/local/lib -L/usr/local/lib -lRandom
echo "Built!"