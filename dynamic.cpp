#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
int main() {
	double x_n = 0.1, r, x_n1;
	r = 3.95;
	ofstream outfile("3.95.txt");
	for (int i = 0; i < 100000; i++) {
		outfile << i << "\t" << x_n << endl;
		x_n1 = r*x_n*(1-x_n);
		x_n = x_n1;
	}
}