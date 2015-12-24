#include <iostream> 
#include <time.h> //для функции time
#include <iomanip> //для setw()
const int NUM = 7; //розмер масива

using namespace std;

typedef int Matrix[10][10];
void initArray(int*, int);
void GetMatrix(int&, int, Matrix);
void Out(int&, Matrix);

void main()
{
	Matrix M;
	srand(time(NULL)); //функія випадковості прив'язана до системного часу
	int n; //Оголошуємо змінну n

	setlocale(LC_ALL, "Ukrainian");
	cout << "Программа побудує квадратну матрицю!";
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
	cout << "Утворюючий масив: ";
	for (int i = 0; i<NUM; i++) //цикл для створення першого рядка поя кому буде побудована матриця
	{
		FArray[i] = rand() % 30;
		
	}
}

void GetMatrix(int &FArray, int NUM, Matrix M)
{
	
	for (int i = 0; i<NUM; i++) //цикл для рядка 
	{
		for (int j = 0; j<NUM; j++) //цикл для комірки
		{
			M[i][j] = (&FArray)[(i + j) % NUM];  //заповнення матриці
		}
		cout << endl;
	}

}

void Out(int &arr, Matrix matr){
	for (int i=0; i<NUM; i++) // цикл для виводу масиву
		cout << setw(2) << (&arr)[i] << "  ";

	cout << "\n---------------------------------------------\n";

	for (int i = 0; i<NUM; i++) //цикл для виводу матриці
	{
		for (int j = 0; j<NUM; j++) //цикл для комірки
			cout << setw(2) << matr[i][j] << " ";  //виведення результату комірки
		cout << endl;
	}
}