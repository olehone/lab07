// Lab_7_2_1.cpp
// Володько Олег Володимирович
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 3
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
int SumMin(int** a, const int n, const int k, int S, int min);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 15;
	int n = 5;
	int k = 5;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n, k, Low, High);
	Print(a, n, k);
	cout << "Sum min = "<< SumMin(a, n, k, 0, 0)<< endl;
	for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int SumMin(int** a, const int n, const int k, int S, int min)
{
	for (int i = 0; i < n; i++)
	{
		min = a[i][0];
		for (int j = 0; j < k; j++)
		{
			if (min > a[i][j])
				min = a[i][j];
		}
		S += min;
	}
	return S;
}