#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

// Побудувати ромб із шириною, заданою з клавіатури 

typedef int Matrix[20][20];
int width; // глобальная переменная Width - ширина ромба
char texture;

void input(Matrix); // ввод матрицы
void output(Matrix); // вывод матрицы на экран

int main() {
	cout << "\nInput rhombus' width: \n"; cin >> width;

	Matrix A; // выделение памяти под матрицу 10х10 - А

	cout << "Input texture's char: \n"; cin >> texture; // заполнитель

	input(A); // Ввод матрицы А (на месте 1 - *, на месте 0 - пробел)
	output(A); // Вывод ромба на экран

	system("pause");
	main();
	return 0;
}

void input(Matrix M) {
	//srand(time(NULL));
	//width = rand()%19+1;
	for (int i = 0; i < width; i++) 
		for (int j = 0; j < width; j++)
			M[i][j] = 0; // матрица становится нулевой

	int mid = int(width/2);
	for (int i = 0; i < mid; i++) {
		for (int j = mid - i; j <= mid + i; j++) // сверху от середины
			M[i][j] = 1; // на месте будущих звездочек ставлю 1
	} 
	for (int i = mid; i < width; i++) {
		for (int j = mid - (width -1 - i); j <= mid + (width - 1 - i); j++)
			M[i][j] = 1; // на месте будущих звездочек ставлю 1
		}
}

void output(Matrix M) {
	for (int i=0; i < width; i++) {
		for (int j=0; j < width; j++) {
			if (M[i][j] == 1)
				printf("%c", texture);
			else
				printf(" ");
		}
		printf("\n");
	}
}