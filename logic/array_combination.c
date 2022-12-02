#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end,
		int index, int r);

void printCombination(int arr[], int n, int r) {
	int data[r];
	combinationUtil(arr, data, 0, n-1, 0, r);
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r) {
	if (index == r) {
		for (int j=0; j<r; j++)
			printf("%d ", data[j]);
		printf("\n");
		return;
	}
	// replace index with all possible elements. The condition
	// "end-i+1 >= r-index" makes sure that including one element
	// at index will make a combination with remaining elements
	// at remaining positions
	for (int i=start; i<=end && end-i+1 >= r-index; i++) {
		printf(">>> i = %d :: arr[%d] = %d\n", i, index, arr[index]);
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1, r);
		printf("<<< <<< i = %d :: data[%d] = %d\n", i, index, data[i]);
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int r = 3;
	int n = sizeof(arr)/sizeof(arr[0]);
	printCombination(arr, n, r);
}
