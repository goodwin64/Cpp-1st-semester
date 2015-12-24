#include <iostream>
#include <math.h>
using namespace std;

/* 1. За заданими двома сторонами трикутника
і куту (в градусах) між ними знайти довжину 
третьої сторони цього трикутника. */


void func()
{
	double a, b, corner_ab;
	cout << "Length of first side:" << endl;
	cin >> a;
	cout << "Length of second side:" << endl;
	cin >> b;
	cout << "A corner between sides(degrees):" << endl;
	cin >> corner_ab;

	double c, c2;
	c2 = pow(a,2) + pow(b,2) - 2*a*b*cos(corner_ab); // квадрат третьей стороны (теор. косинусов)
	c = sqrt(c2);

	cout << "Length of third side is " << c << endl;

	system("pause");
}

int main()
{
	func();
	return 0;
}