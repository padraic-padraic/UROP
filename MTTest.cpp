#include <RandomLib/Random.hpp>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
int main() {
	cout << "Hello, World!" << endl;
	RandomLib::Random r;
	srand (time(NULL));
	unsigned int seed = rand()%100;
	r.Seed(seed);
	cout << "Using " << r.Name() << " with seed " << r.SeedString() << endl;
}