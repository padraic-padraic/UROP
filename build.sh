#!/bin/sh
echo "Moving in."
cd /home/padraic/Projects/UROP
echo "Cleaning up"
rm ./ MTTest
rm ./MTTest.o
echo "Step 1"
g++ -c -g -O3 MTTest.cpp -I/usr/local/include
echo "Step 2"
g++ -g -o MTTest MTTest.o -L /usr/local/lib -lRandom
echo "Step 3"
g++ -g -o MTTest MTTest.o -L /usr/local/lib -lRandom
echo "Built!"