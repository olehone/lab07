// Lab_7_2_2.cpp
// Володько Олег Володимирович
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 3
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
int Min(int** a, const int k, const int n, int ni, int ki, int min)
{
	if (ki < k)
	{
		if (min > a[ni][ki])
		{
			min = a[ni][ki];
		}
		Min(a, k, n, ni, ki + 1, min);
	}
	else return min;
}
int SumMin(int** a, const int n, const int k, int ni, int ki, int S)
{
	int min = 0;
	if (ni < n)
	{
		min = Min(a, k, n, ni, 0, 15);
		S += min;
		SumMin(a, n, k, ni + 1, ki, S);
	}
	else return S;
}
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
	CreateRows(a, n, Low, High, 0);
	PrintRows(a, n, 0);;
	cout << "Sum min = " << SumMin(a, n, k, 0, 0, 0) << endl;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}