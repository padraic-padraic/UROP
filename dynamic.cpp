#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int main() {
	double x_n, r, x_n1;
	r = 3.3;
	for (r; r < 4.1; r += 0.1) {
		ofstream outifle(r+".txt");
		for (int i = 0; i < 100000; i++) {
			outfile << i << "\t" << x_n << endl;
			x_n = 0.1;
			x_n1 = r*x_n*(1-x_n);
			x_n = x_n1;
		}
	}
}