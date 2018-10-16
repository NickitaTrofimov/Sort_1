#include "pch.h"
#include <iostream>
#include <ctime>


using namespace std;
int main()
{
	int l;
	int c;
	cout << "Enter lines of massive ";
	cin >> l;
	cout << "Enter column of massive ";
	cin >> c;

	int **matrix = new int*[l];

	for (int i = 0; i < l; i++) {
		matrix[i] = new int[c];
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			matrix[i][j] = -10 + rand() % 20;
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	
	int *arr = new int[c];
	int cup, g;
	int i = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			arr[j] = matrix[i][j];
		}

		for (int i = 0; i < c - 1; i++) {
			for (int j = 0; j < c - 1; j++) {
				if (arr[j + 1] < arr[j]) {
					cup = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = cup;
				}
			}
		}

		g = c / 2;
		matrix[i][g] = arr[c - 1];
		
		for (int j = c-2; j >= 1; j--) {
			g--;
			matrix[i][g] = arr[j];
			j--;
		}

		g = c / 2;

		for (int j = c - 3; j >= 0; j--) {
			g++;
			matrix[i][g] = arr[j];
			j--;
		}
	}

	cout << endl;
	cout << "Final matrix: " << endl;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
