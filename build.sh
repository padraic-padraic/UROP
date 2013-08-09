#!/bin/sh
echo "Moving in."
cd /home/padraic/Projects/UROP
echo "Cleaning up"
rm ./stochastic
rm ./stochastic.o
rm ./stochastic2
rm ./stochastic2.o
echo "Step 1"
g++ -c -g -O3 ./stochastic.cpp -I /usr/local/include
echo "Step 1 (New code)"
g++ -c -g -O3 ./stochastic2.cpp -I /usr/local/include
echo "Step 2"
g++ -g -o stochastic stochastic.o -L /usr/local/lib -l Random
echo "Step 2 (New code)"
g++ -g -o stochastic2 stochastic2.o -L /usr/local/lib -l Random
echo "Step 3"
g++ -g -o stochastic stochastic.o -Wl,-rpath=/usr/local/lib -L/usr/local/lib -lRandom
echo "Step 3 (New code)"
g++ -g -o stochastic2 stochastic2.o -Wl,-rpath=/usr/local/lib -L/usr/local/lib -lRandom
echo "Built!"