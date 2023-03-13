#include <iomanip>
#include <iostream>
#include <time.h>
#include <cmath>


using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void Triangulating(int** a, const int rowCount, const int colCount);
int CountOfRows(int** a,const int rowCount,const int colCount,const int input);
void Change(int** a, const int rowCount, const int colCount, int currentRow);


int main()
{
	srand((unsigned)time(NULL));

	int Low = -7;
	int High = 7;
	int input;

	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount; 

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	//Create(a, rowCount, colCount, Low, High);
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	Triangulating(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	cout << "Enter a number = ";
	cin >> input;
	cout << "Result = " << CountOfRows(a, rowCount, colCount,input);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low * rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount) {
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "] [" << j << "] =";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount) {
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int CountOfRows(int** a,const int rowCount,const int colCount,const int input)
{
	int	resultCount = 0;
	int sumOfRowElements = 0;

	for (int i = 0; i < rowCount; i++)
	{
		
		for (int j = 0; j < colCount; j++)
		{
			sumOfRowElements += a[i][j];
		}
		if (sumOfRowElements / colCount < input)
		{
			resultCount++;
		}

		sumOfRowElements = 0;
	}

	return resultCount;
}

void Triangulating(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount -1; i++)
	{
		Change(a, i, rowCount, colCount);
	}
}

void Change(int** a, int currentRow, const int rowCount, const int colCount)
{
	if (a[currentRow][currentRow] == 0)
	{
		cout << "Error";
		return;
	}

	for (int j = 0; j < colCount; j++)
	{
		a[currentRow][j] = a[currentRow][j] / a[currentRow][currentRow];
	}
	for (int i = 0; i < rowCount; i++)
	{
		if (i > currentRow)
		{
			a[i][currentRow] = a[i][currentRow] - a[currentRow][currentRow] * a[i][currentRow];
		}
	}

}