#include <Randomlib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	RandomLib::Random r; //Random number object from the Random Lib implementation of SFMT Algorithm
	r.ReSeed(); //Seeding implementation from Random Lib
	int time;
	; /* Generates integer in range 0-10 
	This line defines variables and gives us a small initial infected population */
	int healthy = 100000 - infected; // Population of 100000
	float prob, norm = infected / 1000000; // Normalise between 0 and 1
	ofstream out ("Stochastic.txt");
	out << "Time step" << "\t" << "Healthy" << "\t" << "Infected" << endl;
	for (time; time < 20000; time++) {
		prob = norm*(1.0 - norm);
		for (int i = 0; i < 100000; i++)
			if (r.floatN() > prob) {
				infected++;
				healthy--;
			}
		out << time << "\t" << healthy << "\t" << infected << endl;
	}
}