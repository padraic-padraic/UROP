#include <RandomLib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	RandomLib::Random r;
	double g = 3.6, x_n, x_n1, sum = 0, sum2 = 0, t = 0;
	r.Reseed();
	x_n = r.IntegerC(1, 10) / 1000;
	fstream outfile("Stoch3.6.txt");
	for (t; t < 20000; t++) {
		for (int i = 0; i < 1000; i++){
			if (r.FixedN() > g*x_n) {
				x_n += 0.001;
			}
			if (r.FixedN() < g*(x_n*x_n)) {
				x_n -= 0.001;
			}
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
}