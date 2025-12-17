#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int fac(int n) {
	if (n == 0) {
		return 1;
	} else if (n > 0) {
		return n * fac(n-1);
	}
}

double pangkat(double angka, int pangkat) {
	double hasil = 1.0;
	for (int i = 0; i < pangkat; i++) {
		hasil*=angka;
	}
	return hasil;
}

double exp1(double x) {
	double suku = 1.0;
	double hasil = 1.0;
	for (int i = 1; i <= 20; i++) {
		suku*=x/i;
		hasil+=suku;
	}
	return hasil;
}


int main () {
	double lambda[9] = {2.0, 3.5, 5.0, 4.2, 1.8, 3.7, 4.6, 2.4, 1.5};
	for (int i = 0; i < 9; i++) {
	//	cout << lambda[i] << endl;
	}
	int x[9];
	double atas;
	double bawah;
	double pdf;

	for (int i = 0; i < 9; i++) {
		x[i] = lambda[i] + 3*sqrt(lambda[i]);
	}
	for (int i = 0;  i < 9; i++) {
		double sum = 0.0;
		cout << "lambda = " << lambda[i] << endl;
		cout << "x\t" << "P(X=x)  " << "P(X<=x)" << endl;
		for (int j = 0; j <= x[i]; j++) {
			atas = exp1(-lambda[i]) * pangkat(lambda[i], j);
			bawah = fac(j);
			pdf = atas / bawah;
			sum +=pdf;
			cout << j << "\t" << pdf << "  " << sum << endl;
		}
	}
	
}
