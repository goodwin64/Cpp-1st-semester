#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

typedef int Matrix[10][10];
int n, m; // ���������� ���������� � � � - ����������� ������

void input(Matrix); // ���� �������
void output(Matrix); // ����� ������� �� �����
void sort_by_Summ(Matrix); // ���������� �� ������-��� ��������

//void add_character(Matrix, int) // ���������� ����� ������� ������� �������������� (�����)
//void swap(int, int); // ������������ 2� ���������
//void swap(Matrix, int, int); // ������������ 2� ��������


int main() {
	Matrix A; // ��������� ������ ��� ������� 10�10 - �
	cout << "Input n, m: \n"; cin >> n >> m; // � ����� � � ��������
	input(A); // ���� ������� �
	cout <<"\nArray before sort:\n"; output(A); // ����� ������� � �� ����������
	sort_by_Summ(A); // ����������
	cout <<"\nArray after sort:\n"; output(A); // ����� ������� � ����� ����������

	system("pause");
	main();
	return 0;
}

void input(Matrix M) {
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			M[i][j] = rand()%21-10; // ��������� ����� �� -10 �� 10
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
	int temp = *a; // ��������� ����������, ������ � ���� �������� �
	*a = *b; // � �������� ������� �������� �
	*b = temp; // � �������� ������� �������� ����, ������� � ���� �
}

void swap_columns(Matrix M, int a, int b) {
	for (int i=0; i<=n; i++)
		swap (M[i][a], M[i][b]); // � ����� ������ ������� �������� �������� a, b
}

void add_character(Matrix M, int col) {
	// -------- ���������� ������-�� � ������� ���� ----------
	int Summ = 0;
	for (int i=0; i<n; i++) {
		if (M[i][col] %2 == -1 && M[i][col] < 0)
			Summ += abs(M[i][col]);
	}
	M[n][col] = Summ;
}

void sort_by_Summ(Matrix M) {
	for (int j = 0; j < m; j++) // ���������� �������������� � ������� �������
		add_character(M, j); 
	// -------- ���������� �������� ��������� ---------------
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - i - 1; j++)
			if (M[n][j] > M[n][j + 1]) // ��������� �������� ��������� � ����� ������ ������
				swap_columns(M, j, j + 1); // ������������ ��������, ���� ����� ����� ������
}