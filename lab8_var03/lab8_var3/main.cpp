#include <iostream>
#include <stdio.h>
#include <ctime>
//#include <iomanip.h>
using namespace std;

/* 3. �� ����� ������ ��������� ������� �(n x n) ���������� �������
�(n x n), �������� bij ��� ������������ ��������� �����: ����� 
aij ����������� �������, ���������� �������� �� �������;
�������� bij ������� ������������� �������� ����������
�������. */

typedef int Matrix[10][10];
Matrix A;
int n;

void input(Matrix);
void output(Matrix);
void max_elem_under_diagonals(Matrix, int);

int main() {
	cout << "Input n: " << endl; cin >> n;
	input(A); //���������� �����
	cout <<"Array1:\n"; output(A); //������� ������������ �����
	max_elem_under_diagonals(A, n); // �������� �� ������ �����������...
	cout <<"Array2:\n"; output(A); //

	system("pause");
	main();
	return 0;
}

void input(Matrix M) {
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			M[i][j] = rand()%9;
	} 
}
void output(Matrix M) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout << M[i][j];
		cout << endl;

	}
}

void max_elem_under_diagonals(Matrix M, int size) {
	int max;
	//int *Array_B = new int[size][size]; //�������� ���'�� �� ����� �����

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
		   max = M[i][j];
		   for (int ii=i+1; ii<n; ii++) {
			   for (int jj=j-ii+i+1; jj<j+ii-i-1; jj++) {
				   if (jj>=0 && jj<=n)
					   if (M[ii][jj] > max)
						   max = M[ii][jj];
			   }
		   }
		   M[i][j] = max;
		}
	}
}