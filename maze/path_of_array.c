#include <stdio.h>
#include <stdlib.h>

int validate[10][10] = {0};
int found = 0;
void traverse_each_element (int a[][5], int row, int column, int Nr, int Nc) {
	if (column < Nc-1)
		traverse_each_element (a, row, column + 1, Nr, Nc);
	else if( row < Nr-1)
		traverse_each_element (a, row + 1, 0, Nr, Nc);
	printf(" >>>  >>>  [%d] [%d] = %d\n", row, column, a[row][column]);
}

int isSafe(int a[][5], int row, int column, int Nr, int Nc) {
	if ((column >=0 && column < Nc) && (row >= 0 && row < Nr) \
			&& validate [row][column] == 0
			&& a[row][column] == 0)
		return 1;
	return 0; 

}
void check (int a[][5], int row, int column, int Nr, int Nc) {
	if (row == Nr-1 && column == Nc-1 ) {
		validate[row][column] = 1;
		printf("there\n");
		for (int i = 0; i < Nr; i++){
			for (int j = 0; j < Nc; j++)
				printf("%d ", validate[i][j]);
			printf("\n");
		}
		found = 1;
	}
	else if (isSafe(a, row, column, Nr, Nc) && !found) {
		validate [row][column] = 1;
//		printf("[%d] [%d] = %d\n", row, column, a[row][column]);
		check (a, row + 1, column, Nr, Nc);
		check (a, row, column + 1, Nr, Nc);
		validate [row][column] = 0;
//		check (a, row, column - 1, Nr, Nc);
//		check (a, row - 1, column, Nr, Nc);
//		printf(" >>> [%d] [%d] = %d\n", row, column, a[row][column]);
	}
	// Back track the path
	if (found && column >=0 && column < Nc && row >= 0 && row < Nr)
		printf(" >>> [%d] [%d] = %d\n", row, column, a[row][column]);
}

int main()
{
	int arr[][5] = {{ 0, 0, 0, 0, 0},
			{ 0,-1, 0, 0, 0},
			{ 0,-1, 0,-1, 0},
			{ 0,-1,-1, 0, 0},
			{ 0,-1, 0,-1, 0}};

//	traverse_each_element (arr, 0, 0, 5, 5);
	check (arr, 0, 0, 5, 5);
}
