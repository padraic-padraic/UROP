#include <RandomLib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	RandomLib::Random r;
	double g = 0.1, x_n, sum = 0, sum2 = 0;
	r.Reseed();
	x_n = r.IntegerC(1, 10) / 1000;
	ofstream outfile("Stochmean.txt");
	for (g; g < 4.1; g += 0.1) {
		for (int i = 0; i < 1000; i++){
			if (r.FixedN() > g*x_n) {
				x_n += 0.001;
			}
			if (r.FixedN() < g*(x_n*x_n)) {
				x_n -= 0.001;
			}
				double m1 = sum / (1001);
				double m2 = sum / (1001);
				outfile << g << "\t" << m1 << "\t" << m2 - (m1*m1) << endl;
		}
	}
}