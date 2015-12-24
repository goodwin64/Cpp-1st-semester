#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

/* 3. Задана послідовність з t цілих чисел. Перевірити, 
чи утворюють вони арифметичну прогресію. Якщо так, 
то визначити різницю цієї прогресії; у противному випадку 
знайти мінімальний елемент послідовності. Замінити
отриманим значенням усі парні елементи послідовності. */

void input_array1(int*);
void input_array2(int*);
void output_array(int*);
int if_arifm_prog(int []);
const int t=5;

int main() {
	//int elem;
	//cout << "\ninput t: "; cin >> t; 

	int Array1[t];
	int Array2[t];

	input_array1(Array1); //генерувати масив
	input_array2(Array2); 
	cout <<"Array1:"; output_array(Array1); 
	cout <<"Array2:"; output_array(Array2); 
	printf("%5d\n" , if_arifm_prog(Array1)); // является ли массив прогрессией...
	printf("%5d\n" , if_arifm_prog(Array2)); 
	cout <<"Array1:"; output_array(Array1); 
	cout <<"Array2:"; output_array(Array2);

	system("pause");
	main();
	return 0;
}

void input_array1(int *p) {
	srand(time(NULL));
	for (int c=0; c<t; c++) {
		*p = rand()%51-20;
		p++;
	} 
}

void input_array2(int Array[]) {
	int elem;
	for (int c=0; c<t; c++) {
		cout << "\ninput element №" << c+1 << ": "; cin >> elem;
		Array[c] = elem;
		//scanf ("%d", Array[c]);
	}
}

void output_array(int *p) {
	//for (c=0; c<t-1; c++)
	//	cout << Array[c] << ", ";
	//cout << Array[c] << endl;
	for (int c=0; c<t; c++)
		printf("%4d", *(p+c));
	printf("\n");
	}

int min_pr(int Arr[]){ // find minimal element in Arr[]
	int infinum = Arr[0];
	for (int c=0; c<t; c++) 
		if (Arr[c] < infinum)
			infinum = Arr[c];
	return infinum;
}

int	if_arifm_prog(int arr[]) {
	bool ar_pr = true;
	//int difference = arr[1] - arr[0];
	int difference = *arr - arr[0];
	int min = min_pr(arr);
	for (int c=0; c<t-1; c++) // цикл проверки разницы ар.прогр.
		if (arr[c+1] - arr[c] != difference) {
			ar_pr = false; // если отличие от разницы
			break; // прекращаем проверять на прогрессию
		}
	if (ar_pr == true) {
		for (int c=0; c<t; c++) {
			if (arr[c]%2 == 0)
				arr[c] = difference;
		}
		return difference;
	}
	else {
		for (int c=0; c<t; c++) {
			if (arr[c]%2 == 0)
				arr[c] = min;
		}
		return min;
	}
}