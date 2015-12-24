#include <iostream>
using namespace std;

/* 3. Дано дійсне число M виду ccc.ddd (по три 
цифрових розряди в дробовій і цілій частинах). 
Поміняти місцями дробову і цілу частини цього 
числа та вивести нове отримане число. */


void func()
{
	double ccc_ddd;
	cout << "Enter your 6-char number:" << endl;
	cin >> ccc_ddd;
	double ccc = int(ccc_ddd);
	double ddd = (ccc_ddd - ccc)*1000;
	double ddd_ccc = ddd + ccc/1000;
	cout << "The number was: " << ccc_ddd << endl;
	cout << "The number is: " << ddd_ccc << endl;

	system("pause");
	func();
}

int main()
{
	func();
	return 0;
}