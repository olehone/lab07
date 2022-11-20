// Lab_7_3_2.cpp
// Володько Олег Володимирович
// Лабораторна робота № 7.3.2
// Опрацювання динамічних, багатовимірних масивів. Рекурсивний спосіб
// Варіант 3
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void CreateRow(int** a, const int rowNo, const int colCount,
	const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}
int Max1(int* a, const int size, int i, int max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max1(a, size, i + 1, max);
	else
		return max;
}
int Find(int* a, const int size, const int x, int i)
{
	if (a[i] == x)
		return i;
	if (i < size - 1)
		return Find(a, size, x, i + 1);
	else
		return -1;
}
int NumbZero2(int** a, const int n, const int k, int& number, int i, int j)
{
	if (i < n)
	{
		if (a[i][j] == 0)
		{
			number += 1;
			return number;
		}
		else NumbZero2(a, n, k, number, i + 1, j);
	}
	else return 0;
}
int NumbZero1(int** a, const int n, const int k, int number, int i, int j)
{
	if (j < k)
	{
		NumbZero2(a, n, k, number, 0, j);
		NumbZero1(a, n, k, number, i, j + 1);
	}
	else return number;
}
void NumbRew2(int** a, const int n, const int k, int Low, int High, int& MaxNumbRow, int i, int j, int& Max, int Max2)
{
	if (j < k - 1)
	{
		if (a[i][j] == a[i][j + 1])
			Max2 += 1;
		else Max2 = 0;
		if (Max < Max2)
			Max = Max2;
		NumbRew2(a, n, k, Low, High, MaxNumbRow, i, j + 1, Max, Max2);
	}
}
void NumbRew1(int** a, int* NumbMass, const int n, const int k, int Low, int High, int& MaxNumbRow, int i, int j, int size)
{
	if (i < n)
	{
		int Max = 0;
		int Max2 = 0;
		NumbRew2(a, n, k, Low, High, MaxNumbRow, i, 0, Max, Max2);
		NumbMass[i] = Max;
		NumbRew1(a, NumbMass, n, k, Low, High, MaxNumbRow, i + 1, j, size);
	}
	MaxNumbRow = Find(NumbMass, size, Max1(NumbMass, 5, 0, 0), 0);
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = 0;
	int High = 15;
	int n = 5;
	int k = 5;
	int MaxNumbRow = 0;
	int Max = 0; 
	int Max2 = 0;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	InputRows(a, n, k, 0);
	PrintRows(a, n, k, 0);
	int NumbMassive[] = {0,0,0,0,0};
	cout << "Numb zero = " << NumbZero1(a, n, k, 0, 0, 0) << endl;
	NumbRew1(a, NumbMassive, n, k, Low, High, MaxNumbRow, 0, 0, 5);
	cout << "Number of row : " << MaxNumbRow + 1 << endl;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}