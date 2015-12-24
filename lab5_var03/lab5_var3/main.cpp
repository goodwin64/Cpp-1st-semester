#include <iostream>
#include <cmath>

using namespace std;

/* 3-3. Дано натуральне число n. Серед чисел 1, ..., n знайти такі, запис яких
співпадає з останніми цифрами запису їх квадрату. Наприклад, 6 ( 6^2 = 36 ),
25 ( 25^2 = 625) і т.д. */

int len(int x) {
	int count = 0;
	while (x > 0) {
		x/=10;
		count++;
	}
	return count;
}

int main() {
	int N, last_c, last_c2;
	bool need;
	int i, i2, c, c2;

	cout << "\nInput N: " << endl; cin >> N;

	for (i=1; i<=N; i++) {
		c = i;
		c2 = pow(c,2.);
		i2 = c2;
		need = true;
		while (c>0) {
			last_c = c%10;
			c /= 10;
			last_c2 = c2%10;
			c2 /= 10;
			if (last_c != last_c2) {
				need = false;
				break;
			}

		}
		if (need == true)
			cout << i << "^2=" << i2 << endl;
	}
	
	system ("pause");
	main();
	return 0;
}