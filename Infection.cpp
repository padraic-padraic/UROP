#include <RandomLib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	RandomLib::Random r; //Random number object from the Random Lib implementation of SFMT Algorithm
	r.Reseed(); //Seeding implementation from Random Lib
	int time;
	int infected = r.IntegerC(0,10); /* Generates integer in range 0-10 
	This line defines variables and gives us a small initial infected population */
	int healthy = 1000 - infected; // Population of 100000
	float prob, norm = infected / 10000; // Normalise between 0 and 1
	ofstream out ("Stochastic.txt");
	cout << time << "\t" << healthy << "\t" << infected << endl;
	out << "Time step" << "\t" << "Healthy" << "\t" << "Infected" << endl;
	for (time, infected; time < 10000 && infected < 1000; time++) {
		cout << time << endl;
		prob = norm*(1.0 - norm);
			if (r.FloatN() > prob) {
				infected++;
				healthy--;
				cout << "Infection!" << infected << endl;	
			}
		out << time << "\t" << healthy << "\t" << infected << endl;
}
}