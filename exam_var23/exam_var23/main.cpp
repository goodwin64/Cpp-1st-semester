#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

// ���������� ���� �� �������, ������� � ��������� 

typedef int Matrix[20][20];
int width; // ���������� ���������� Width - ������ �����
char texture;

void input(Matrix); // ���� �������
void output(Matrix); // ����� ������� �� �����

int main() {
	cout << "\nInput rhombus' width: \n"; cin >> width;

	Matrix A; // ��������� ������ ��� ������� 10�10 - �

	cout << "Input texture's char: \n"; cin >> texture; // �����������

	input(A); // ���� ������� � (�� ����� 1 - *, �� ����� 0 - ������)
	output(A); // ����� ����� �� �����

	system("pause");
	main();
	return 0;
}

void input(Matrix M) {
	//srand(time(NULL));
	//width = rand()%19+1;
	for (int i = 0; i < width; i++) 
		for (int j = 0; j < width; j++)
			M[i][j] = 0; // ������� ���������� �������

	int mid = int(width/2);
	for (int i = 0; i < mid; i++) {
		for (int j = mid - i; j <= mid + i; j++) // ������ �� ��������
			M[i][j] = 1; // �� ����� ������� ��������� ������ 1
	} 
	for (int i = mid; i < width; i++) {
		for (int j = mid - (width -1 - i); j <= mid + (width - 1 - i); j++)
			M[i][j] = 1; // �� ����� ������� ��������� ������ 1
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