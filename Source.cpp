// Lab_7_3_1.cpp
// Володько Олег Володимирович
// Лабораторна робота № 7.3.1)
// Опрацювання динамічних, багатовимірних масивів. Ітераційний спосіб
// Варіант 3
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
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
int NumbZero(int** a, const int n, const int k, int number)
{
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] == 0)
			{
				number += 1;
				break;
			}
		}
	}
	return number;
}
int Max(int* a, const int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}
int Find(int* a, const int size, const int x)
{
	for (int i = 0; i < size; i++)
		if (a[i] == x)
			return i;
	return -1;
}
void NumbRew(int **a, const int n, const int k, int Low, int High, int& MaxNumbRow)
{
	int NumbMass[] = {0,0,0,0,0};
	for (int i = 0; i < n; i++)
	{
		int Max = 0;
		int Max2 = 0;
		for (int j = 0; j < k-1; j++)
		{
			if (a[i][j] == a[i][j + 1])
				Max2 += 1;
			else Max2 = 0;
			if (Max < Max2)
				Max = Max2;
		}
		NumbMass[i] = Max;
	}
	MaxNumbRow = Find(NumbMass, 5, Max(NumbMass, 5));
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 15;
	int n = 5;
	int k = 5;
	int MaxNumbRow = 0;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n, k, Low, High);
	Input(a, n, k);
	Print(a, n, k);
	cout << "Numb zero = " << NumbZero(a, n, k, 0) << endl;
	NumbRew(a, n, k, Low, High, MaxNumbRow);
	cout << "Number of row : " << MaxNumbRow + 1 << endl;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}