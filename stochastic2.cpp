#include <RandomLib/Random.hpp>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
double factorial(int n){
	int tot = 1;
	for (int i = 1; i < n+1; i++){
		tot *= i;
	}
	return tot;
}

int main() {
	//ofstream test("stoch2.txt");
	ofstream means("2mean.txt");
	ofstream delta("deltamean.txt");
	RandomLib::Random r;
	r.Reseed();
	const int k = 500; // Carrying capacity
	int x_n = 120, x_n1; // Initial value
	int deltac, deltad, deltab; //Competition, Death and Birth changes per time-step
	double alpha, beta = 0.57 * k;
	double p_b, p_c, p_d;
	int n, m; // m is a uniform random variable between o and n at time t_n
	double count = 0.0;
	int loopcount;
	double fact; //container for factorials
	double sum, sum_2, sumb, sumc, sumd, sumb_2, sumc_2, sumd_2;
	double mean, var, mb, mc, md, varb, varc, vard;
	for (int loopcount = 0; loopcount < 2001; loopcount++) {
		alpha = (beta/k) + (count/k);
		cout << count << endl;
		cout << alpha << endl;
		sum = 0;
		sum_2 = 0;
		sumb = 0;
		sumb_2 = 0;
		sumc = 0;
		sumc_2 = 0;
		sumd = 0;
		sumd_2 = 0;
		x_n = 120;
		for (int t = 0; t < 10000; t++) {
			n = x_n;
			sum += x_n;
			sum_2 += pow(x_n, 2);
			//cout << t << "\t" << x_n << endl;
			//test << t << "\t" << x_n << endl;
			deltab = 0;
			deltac = 0;
			deltad = 0;
			m = r.IntegerC(0, n);
			//cout << m << endl;
			fact = factorial(m);
			//cout << "calculating p_b" << endl; 
			p_b = pow(alpha, m) * exp(-1 * alpha) / fact;
			//cout << "calculating p_c" << endl;
			p_c = 2.0 / (k * (1+m) );
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
				deltac = m;
			}
			x_n1 = x_n + deltab - deltad - deltac;
			x_n = x_n1;
			sumd += deltad;
			sumc += deltac;
			sumb += deltab;
			sumb_2 += (deltab * deltab);
			sumc_2 += (deltac * deltac);
			sumd_2 += (deltad * deltad);
		} //After running for 10000 timesteps, means and variances are calculated for x and all deltas at a given alpha
		mean = sum / 10000;
		var = (sum_2 / 10000) - (mean*mean);
		mc = sumc / 10000;
		varc = (sumc_2 / 10000) - (mc*mc);
		mb = sumb / 10000;
		varb = (sumb_2 / 10000) - (mb*mb);
		md = sumd / 10000;
		vard = (sumd_2 / 10000) - (md*md);
		means << alpha << "\t" << mean << "\t" << var << endl;
		delta << alpha << "\t" << mb << "\t" << varb << "\t" << mc << "\t" << varc << "\t" << md << "\t" << vard << endl;
		count += 1.0;
	}
}