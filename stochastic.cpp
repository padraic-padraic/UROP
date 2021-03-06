#include <RandomLib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	RandomLib::Random r;
	double g = 3.57, x_n, x_n1, sum = 0, sum2 = 0, t = 0, random;
	r.Reseed();
	x_n = 0.2;
	ofstream outfile("Stoch3.57.txt");
	for (t; t < 20000; t++) {
		if (r.FixedN()< g*x_n) {
			x_n += 0.001;
		}
		if (r.FixedN() < g*(x_n*x_n)) {
			x_n -= 0.001;
		}
		outfile << t << "\t" << x_n << endl;
		sum += x_n;
		sum2 += (x_n*x_n);
	}
	double m1 = sum / (t+1);
	double m2 = sum / (t+1);
	cout << "The mean is " << m1 << endl;
	cout << "The Variance is " << m2 - (m1*m1) << endl;
	cout << "The value of g is " << g << endl;
	cout << "Mean calculations...." << endl;
	ofstream outfile2("Stochmean.txt");
	for (g = 0.1; g < 4.5; g += 0.01) {
		x_n = 0.1; 
		//cout << x_n << endl;
		sum = 0;
		sum2 = 0;
		for (int i = 0; i < 20000; i++){
			if (r.FixedN() < g*x_n) {
				x_n += 0.001;
			}
			if (r.FixedN() < g*(x_n*x_n)) { // Should test random or Random squared? Same or different random number?
				x_n -= 0.001;
			}
			sum += x_n;
			sum2 += (x_n*x_n);
		}
		m1 = sum / (20000);
		m2 = sum / (20000);
		outfile2 << g << "\t" << m1 << "\t" << m2 - (m1*m1) << endl;
		//cout << g << endl;
	}
}