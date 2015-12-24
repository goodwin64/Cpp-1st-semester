#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

typedef int Matrix[10][10];
int n, m; // глобальные переменные Н и М - размерность матриц

void input(Matrix); // ввод матрицы
void output(Matrix); // вывод матрицы на экран
void sort_by_Summ(Matrix); // сортировка по характ-кам столбцов

//void add_character(Matrix, int) // добавление снизу каждого столбца характеристики (Суммы)
//void swap(int, int); // перестановка 2х элементов
//void swap(Matrix, int, int); // перестановка 2х столбцов


int main() {
	Matrix A; // выделение памяти под матрицу 10х10 - А
	cout << "Input n, m: \n"; cin >> n >> m; // Н строк и М столбцов
	input(A); // Ввод матрицы А
	cout <<"\nArray before sort:\n"; output(A); // Вывод матрицы А до сортировки
	sort_by_Summ(A); // сортировка
	cout <<"\nArray after sort:\n"; output(A); // Вывод матрицы А после сортировки

	system("pause");
	main();
	return 0;
}

void input(Matrix M) {
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			M[i][j] = rand()%21-10; // случайное число от -10 до 10
	} 
	for (int j=0; j<m; j++)
			M[n][j] = 0;
}

void output(Matrix M) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			printf("%4d", M[i][j]);
		cout << endl;
	}
	printf("-------------------------\n");
	for (int j=0; j<m; j++)
		printf("%4d", M[n][j]);
	cout << endl;
}

void swap(int* a, int* b) {
	int temp = *a; // временная переменная, держит в себе значение А
	*a = *b; // А начинает держать значение Б
	*b = temp; // Б начинает держать значение Темп, которое и есть А
}

void swap_columns(Matrix M, int a, int b) {
	for (int i=0; i<=n; i++)
		swap (M[i][a], M[i][b]); // в цикле меняет местами элементы столбцов a, b
}

void add_character(Matrix M, int col) {
	// -------- Добавление характ-ки к столбцу вниз ----------
	int Summ = 0;
	for (int i=0; i<n; i++) {
		if (M[i][col] %2 == -1 && M[i][col] < 0)
			Summ += abs(M[i][col]);
	}
	M[n][col] = Summ;
}

void sort_by_Summ(Matrix M) {
	for (int j = 0; j < m; j++) // добавление характеристики к каждому столбцу
		add_character(M, j); 
	// -------- Сортировка столбцов пузырьком ---------------
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - i - 1; j++)
			if (M[n][j] > M[n][j + 1]) // сравнение соседних элементов в самой нижней строке
				swap_columns(M, j, j + 1); // перестановка столбцов, если сумма слева больше
}