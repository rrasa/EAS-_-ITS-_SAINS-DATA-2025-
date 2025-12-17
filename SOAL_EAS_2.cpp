#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Data {
	char kode;
	double harga;
	double iklan;
	double pennjualan;
};

double rataRata (double rata[], int n) {
	double hasil = 0.0;
	for (int i = 0; i < n; i++) {
		hasil+=rata[i];
	}
	return hasil / n;
}

double corr(double x[], double y[], int n) {
	double atas = 0.0, bawah = 0, bawah1 = 0;
	double rataX = 0, rataY = 0, sumX = 0.0, sumY = 0.0;
	double corr;
	for (int i = 0; i < n; i++) {
		sumX+=x[i];
		sumY+=y[i];
		atas+=x[i]*y[i];
		bawah+=x[i]*x[i];
		bawah1+=y[i]*y[i];
	}
		rataX = sumX / n;
		rataY = sumY / n;
	atas-=n*rataX*rataY;
	bawah-=n*rataX*rataX;
	bawah1-=n*rataY*rataY;  
	corr = atas / (sqrt(bawah) * sqrt(bawah1));
	return corr;
}

int main () {
	Data data[100];
	double x[100],y[100],z[100];
	ifstream infile("dataset.txt");
	int i = 0;
	while(infile >> data[i].kode >> data[i].harga >> data[i].iklan >> data[i].pennjualan)  {
		x[i] = data[i].harga;
		y[i] = data[i].iklan;
		z[i] = data[i].pennjualan;
		i++;
	}
	infile.close();
	cout << "5 Data Pertama = " << endl;
	for (int j = 0; j < 5; j++) {
		cout << data[j].kode << " " << data[j].harga << " " << data[j].iklan << " " << data[j].pennjualan << endl;
	}
	cout << endl;
	cout << "Jumlah Kode = " << endl;
	int count = 0, count1 = 0, count2 = 0, count3 = 0;
	for (int k = 0; k < i; k++) {
		if (data[k].kode == 'A') {
			count++;
		}
		if (data[k].kode == 'B') {
			count1++;
		}
		if (data[k].kode == 'C') {
			count2++;
		}
		if (data[k].kode == 'D') {
			count3++;
		}	
	}
	cout << "A = " << count << endl;
	cout << "B = " << count1 << endl;
	cout << "C = " << count2 << endl;
	cout << "D = " << count3 << endl;
	
	cout << endl << "Rata - rata per kode (Harga / Iklan / Penjualan): " << endl;
	double rataA, rataA1, rataA2;
	double sumA = 0, sumA1 = 0, sumA2 = 0;
	double rataB, rataB1, rataB2;
	double sumB = 0, sumB1 = 0, sumB2 = 0;
	double rataC, rataC1, rataC2;
	double sumC = 0, sumC1 = 0, sumC2 = 0;
	double rataD, rataD1, rataD2;
	double sumD = 0, sumD1 = 0, sumD2 = 0;
	for (int j = 0; j < i; j++) {
		if(data[j].kode == 'A') {
			sumA+=data[j].harga;
			sumA1+=data[j].iklan;
			sumA2+=data[j].pennjualan;
			rataA = sumA / count;
			rataA1 = sumA1 / count;
			rataA2 = sumA2 / count;
		}
		if(data[j].kode == 'B') {
			sumB+=data[j].harga;
			sumB1+=data[j].iklan;
			sumB2+=data[j].pennjualan;
			rataB = sumB / count1;
			rataB1 = sumB1 / count1;
			rataB2 = sumB2 / count1;
		}
		if(data[j].kode == 'C') {
			sumC+=data[j].harga;
			sumC1+=data[j].iklan;
			sumC2+=data[j].pennjualan;
			rataC = sumC / count2;
			rataC1 = sumC1 / count2;
			rataC2 = sumC2 / count2;
		}
		if(data[j].kode == 'D') {
			sumD+=data[j].harga;
			sumD1+=data[j].iklan;
			sumD2+=data[j].pennjualan;
			rataD = sumD / count3;
			rataD1 = sumD1 / count3;
			rataD2 = sumD2 / count3;
		}
	}
	cout << "A: " << rataA << " " << rataA1 << " " << rataA2 << endl;
	cout << "B: " << rataB << " " << rataB1 << " " << rataB2 << endl;
	cout << "C: " << rataC << " " << rataC1 << " " << rataC2 << endl;
	cout << "D: " << rataD << " " << rataD1 << " " << rataD2 << endl;
	
	cout << endl;
	double korelasi1 = corr(x,x,i);
	double korelasi2 = corr(x,y,i);
	double korelasi3 = corr(x,z,i);
	double korelasi4 = corr(y,x,i);
	double korelasi5 = corr(y,y,i); 
	double korelasi6 = corr(y,z,i);
	double korelasi7 = corr(z,x,i);
	double korelasi8 = corr(z,y,i);
	double korelasi9 = corr(z,z,i);
	cout << "Matriks Korelasi = " << endl;
	cout <<  korelasi1 << " " << korelasi2 << " " << korelasi3 << endl;
	cout << korelasi4 << " " << korelasi5 << " " << korelasi6 << endl;
	cout <<  korelasi7 << " " << korelasi8 << " " << korelasi9 << endl;
	
}

