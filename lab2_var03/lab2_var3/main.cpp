#include <iostream>
#include <cmath>

using namespace std;

/* 3. Дослідити область визначення і обчислити значення 
функції y(x) = sqrt(x+4) */

int main() {
	double x, y;
	cout << "\nInput x:" << endl; cin >> x;
	if (x+4 < 0) {
		cout << "y value isn't in real-part area" << endl;
		y = sqrt(abs(x+4));
		cout << "y=" << y << "i" << endl;
	} else {
		double y = sqrt(x+4);
		cout << "y=" << y << endl;
	}
	system ("pause");
	main();
	return 0;
}