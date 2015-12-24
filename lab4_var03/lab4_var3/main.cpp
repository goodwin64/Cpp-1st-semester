#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

/* 3. З точнiстю 1E-5 обчислити: */

int main() {
	double Summ=0, x, ak1 = 0, ak2 = 0, delta=0.00001;
	int n=0;

	//scanf("acc: %f, x: %f", &delta, &x);
	//cout << "\nInput accuracy: "; cin >> delta;
	cout << "\nInput X (0<X<1): "; cin >> x;

	do
	 {
		ak1 = ak2;
		ak2 = pow(-1.,n)*(pow(x,2*n)+1)/(pow(2.,n)+1);
		//cout //<< "timely ak = " << ak2 << endl
		 //<< "timely n = " << n << endl
		 //<< "timely ak2-ak1 = " << ak2-ak1 << endl;
		printf("temporarily |ak2| - |ak1| = %10.7f\n", abs(ak2) - abs(ak1));
		Summ += ak2;
		n++;
	}
	while (abs(abs(ak2) - abs(ak1)) > delta);
	cout << "Summ = " << Summ << endl;
	system ("pause");
	main();
	return 0;
}