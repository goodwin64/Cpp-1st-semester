#include <iostream> 
#include <time.h> //��� ������� time
#include <iomanip> //��� setw()
const int NUM = 7; //������ ������

using namespace std;

typedef int Matrix[10][10];
void initArray(int*, int);
void GetMatrix(int&, int, Matrix);
void Out(int&, Matrix);

void main()
{
	Matrix M;
	srand(time(NULL)); //����� ����������� ����'����� �� ���������� ����
	int n; //��������� ����� n

	setlocale(LC_ALL, "Ukrainian");
	cout << "��������� ������ ��������� �������!";
	cout << endl << endl;

	int FArray[NUM];

	initArray(FArray, NUM);
	 

	GetMatrix(*FArray, NUM, M);
	Out(*FArray, M);
	cout << endl;
	system("pause");
	
}

void initArray(int *FArray, int NUM)
{
	cout << "���������� �����: ";
	for (int i = 0; i<NUM; i++) //���� ��� ��������� ������� ����� ��� ���� ���� ���������� �������
	{
		FArray[i] = rand() % 30;
		
	}
}

void GetMatrix(int &FArray, int NUM, Matrix M)
{
	
	for (int i = 0; i<NUM; i++) //���� ��� ����� 
	{
		for (int j = 0; j<NUM; j++) //���� ��� ������
		{
			M[i][j] = (&FArray)[(i + j) % NUM];  //���������� �������
		}
		cout << endl;
	}

}

void Out(int &arr, Matrix matr){
	for (int i=0; i<NUM; i++) // ���� ��� ������ ������
		cout << setw(2) << (&arr)[i] << "  ";

	cout << "\n---------------------------------------------\n";

	for (int i = 0; i<NUM; i++) //���� ��� ������ �������
	{
		for (int j = 0; j<NUM; j++) //���� ��� ������
			cout << setw(2) << matr[i][j] << " ";  //��������� ���������� ������
		cout << endl;
	}
}