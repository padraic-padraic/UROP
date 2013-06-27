#include <RandomLib/Random.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int main() {
	cout << "Hello, World!" << endl;
	RandomLib::Random r;
	r.Reseed();
	cout << "Using " << r.Name() << " with seed " << r.SeedString() << endl;
	for (int i = 0; i < 1000; i++)
	{
		cout << r.FloatN() << endl;
	}
}