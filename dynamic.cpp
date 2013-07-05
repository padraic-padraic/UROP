#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
	double x_n = 0.1, r, x_n1, x2_n = 0.2, x2_n1, delta, delta0;
	int loopcount = 1;
	ofstream outfile("3.95.txt");
	ofstream cob6("cobweb3.6.txt");
	ofstream cob7("cobweb3.7.txt");
	ofstream cob8("cobweb3.8.txt");
	ofstream cob9("cobweb3.9.txt");
	ofstream Liapunov("exponent.txt");
	ofstream orbit("orbit.txt");

void dynamic(int p, double r) {
	for (r; r < 4.2; r += 0.01) {
			x_n = 0.1;
			x2_n = 0.2 + (p*0.05);
			delta0 = x2_n - x_n;
			cout << r << endl;
			cout << delta0 << endl;
			for (int i = 0; i < 300; i++) {
				//outfile << i << "\t" << x_n << endl;
				x_n1 = r*x_n*(1-x_n);
				x2_n1 = r*x2_n*(1- x2_n);
				switch(loopcount) {
					case 11: 
					//cout << "Cobweb3.6!" << endl;
					cob6 << x_n << "\t" << x_n1 << endl;
					break;
					case 21:
					//cout << "Cobweb3.7!" << endl;
					cob7 << x_n << "\t" << x_n1 << endl;
					break;
					case 31:
					//cout << "Cobweb 3.8!" << endl;
					cob8 << x_n << "\t" << x_n1 << endl;
					break;
					case 41:
					//cout << "Cobweb 3.9" << endl;
					cob9 << x_n << "\t" << x_n1 << endl;
					break;
				}
				if (i > 500) {
					orbit << r << "\t" << x_n << "\t" << x_n1 << endl;
					//cout << "orbit out" << endl;
				}
				x_n = x_n1;
				x2_n = x2_n1;
			}
			loopcount++;
			delta = x2_n - x_n;
			cout << delta << endl;
			long double lambda = log(delta / delta0) / 1000;
			Liapunov << r << "\t" << delta0 << "\t" << lambda << endl;
			cout << "Liapunov is " << lambda << " for r " << r << " and delta init " << delta0 << endl;
		}
}

int main() {
	int p = 0;
	for (p; p < 10; p++){
		r = 3.5;
		dynamic(p, r);
		cout << p << endl;
	}
}