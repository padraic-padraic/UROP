#include <RandomLib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
double factorial (int n){
	int i = 1, tot = 1;
	do {
		tot *= i;
		i++;
	} while (i < n);
	return tot;
}

int main() {
	ofstream test("stoch2.txt");
	ofstream means("2mean.txt");
	ofstream delta("deltamean.txt");
	RandomLib::Random r;
	r.Reseed();
	const int k = 500; // Carrying capacity
	int x_n = 120, x_n1; // Initial value
	int deltac, deltad, deltab; //Competition, Death and Birth changes per time-step
	double alpha, beta = 3.57 * k;
	double p_b, p_c, p_d;
	int n, m; // Counting variable
	double fact; //container for factorials
	int sum = 0, sum_2 = 0, sumb = 0, sumc = 0, sumd = 0, sumb_2 = 0, sumc_2 = 0, sumd_2 = 0;
	double mean, var, mb, mc, md, varb, varc, vard;
	for (int count = 0; count < 500; count++) {
		alpha = (beta/k) + (count/k);
		cout << count << endl;
		for (int t = 0; t < 10000; t++) {
			n = x_n;
			//cout << t << "\t" << x_n << endl;
			test << t << "\t" << x_n << endl;
			deltab = 0;
			deltac = 0;
			deltad = 0;
			m = r.IntegerC(0, n);
			//cout << m << endl;
			fact = factorial(m);
			//cout << "calculating p_b" << endl; 
			p_b = pow(alpha, m) * exp(-1 * alpha) / fact;
			//cout << "calculating p_c" << endl;
			p_c = 2.0 / (k * (1-m) );
			//cout << "calculated p_c" << endl;
			//cout << "calculating P_d" << endl;
			p_d = exp(-1)/ fact;
			if (r.FixedN() < p_b) {
				deltab += m;
				//cout << m << " born!" << endl;
			}
			if (n < k) {
				if (r.FixedN() < p_c) {
					deltac += m;
				//	cout << m << " died through scarcity!" << endl;
				}
				if (r.FixedN() < p_d){
					deltad += m;
				//	cout << m << " died!" << endl;
				}
			}
			else {
				deltad = m;
			}
			x_n1 = x_n + deltab - deltad - deltac;
			x_n = x_n1;
			sumd += deltad;
			sumc += deltac;
			sumb += deltab;
			sumb_2 += (deltab * deltab);
			sumc_2 += (deltac * deltac);
			sumd_2 += (deltad * deltad);
		}
		sum += x_n;
		sum_2 += (x_n * x_n);
		mean = sum / 500;
		var = (sum_2 / 500) - (mean*mean);
		mc = sumc / 500;
		varc = (sumc_2 / 500) - (mc*mc);
		mb = sumb / 500;
		varb = (sumb_2 / 500) - (mb*mb);
		md = sumd / 500;
		vard = (sumd_2 / 500) - (md*md);
		means << alpha << "\t" << mean << "\t" << var << endl;
		delta << alpha << "\t" << mb << "\t" << varb << "\t" << mc << "\t" << varc << "\t" << md << "\t" << vard << endl;
	}
}