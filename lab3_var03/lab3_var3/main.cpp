#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

/* 3. ����� �0 = 1; �k = k*�(k-1) + 1/k, k = 1, 2, � .
��� �������� ������������ n �������� �n. */

int main() {
	double an = 1;
	int n;

	cout << "\nInput integer N:" << endl; cin >> n;

	if ( (n<1) || (int(n)!=n) ) 
		cout << "ERROR: N must be an integer" << endl;
	else {
		for (int k=1; k<=n; k++)
			an = k*an + 1.0/k;
		cout << "an = " << an << endl;
	}

	system ("pause");
	main();
	return 0;
}