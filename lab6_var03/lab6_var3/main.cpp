#include <iostream>

using namespace std;

float max(float a, float b){
	if (a>b)
		return a;
	else 
		return b;
}

int main() {
	float a,b,c,T;

	cout << "\ninput A: "; cin >> a;
	cout << "\ninput B: "; cin >> b;
	cout << "\ninput C: "; cin >> c;

	T = ( max(a,a+b) + max(a,b+c) )/(1 + max(a+b*c, 1.15) );
	cout << "T = (" << max(a,a+b) << " + " << max(a,b+c) << ") / " << "(1 + " << max(a+b*c, 1.15) << ") = " << T << endl;

	system("pause");
	main();
	return 0;
}