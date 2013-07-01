#!/bin/sh
echo "Moving in."
cd /home/padraic/Projects/UROP
echo "Cleaning up"
rm ./stochastic
rm ./stochastic.o
echo "Step 1"
g++ -c -g -O3 ./stochastic.cpp -I /usr/local/include
echo "Step 2"
g++ -g -o stochastic stochastic.o -L /usr/local/lib -l Random
echo "Step 3"
g++ -g -o stochastic stochastic.o -Wl,-rpath=/usr/local/lib -L/usr/local/lib -lRandom
echo "Built!"