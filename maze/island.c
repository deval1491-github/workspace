#include <stdio.h>
#include <stdlib.h>

int validate[10][10] = {0};
int count = 0;

int isSafe(int a[][5], int row, int column, int Nr, int Nc) {
	if ((column >=0 && column < Nc) && (row >= 0 && row < Nr) \
			&& validate [row][column] == 0 \
			&& a[row][column] == 1)
		return 1;
	return 0; 

}

void check (int a[][5], int row, int column, int Nr, int Nc) {

	if (isSafe(a, row, column, Nr, Nc)) {
		validate [row][column] = 1;
//		printf("[%d] [%d] = %d\n", row, column, a[row][column]);

		check (a, row + 1, column, Nr, Nc);
		check (a, row, column + 1, Nr, Nc);
		check (a, row - 1, column, Nr, Nc);
		check (a, row, column - 1, Nr, Nc);
		printf("[%d][%d] > ", row, column);
	}
}


void get_island_count (int a[][5], int row, int column, int Nr, int Nc) {

	for (int i = 0; i < Nr; i++) {
		for (int j = 0; j < Nc; j++) {
			if (isSafe(a, i, j, Nr, Nc)) {
//				printf(" ------- [%d] [%d] = %d\n", i, j, a[i][j]);
				count++;
				printf("Island [%d] = ", count);
				check (a, i, j, Nr, Nc);
				printf("\n");
//				for (int i = 0; i < 5; i++)
//				{
//					for (int j = 0; j< 5; j++)
//						printf("%d ", validate[i][j]);
//					printf("\n");
//				}	
			}
		}
	}
}

int main()
{
	int arr[][5] = {{ 1, 0, 1, 0, 0},
			{ 1, 0, 0, 1, 1},
			{ 1, 0, 1, 0, 1},
			{ 1, 0, 1, 1, 1},
			{ 1, 0, 1, 0, 1}};

	get_island_count (arr, 0, 0, 5, 5);
#if 0
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j< 5; j++)
			printf("%d ", validate[i][j]);
		printf("\n");
	}	
#endif
	printf("count = %d\n", count);
}
