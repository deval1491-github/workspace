#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {

	int arr[] = {10, 80, 30, 90, 40, 50, 70};
	int len = sizeof(arr) / sizeof (*arr);
	int median = len/2;
	int *l = &arr[0];
	int *r = &arr[len-1];
	int *m = &arr[median];

	swap(l, m);

	for (int i = 0; i< len; i++)
		printf("%d ", arr[i]);
	printf("\n");
//	while ( l != m || r != m){
//		if(*l > *m)
//			swap(l, m);
//
//	}
	return 0;
}
