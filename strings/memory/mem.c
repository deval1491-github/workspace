#include<stdio.h>
#include<stdlib.h>

typedef struct my_struct {
	char a;
	char b;
	char seq;
	unsigned int byte;
	char d;
} my_t;

void print_values(my_t *arr) {
	printf("0x%x :: %d :: 0x%x\n", arr->seq, arr->byte, arr->d);
}

void my_func (char* arr, int size) {

	my_t *my = (my_t*) malloc (sizeof(char) * size);
	my->a = (char) arr[0];
	my->b = (char) arr[1];
	my->seq = (char) arr[2];
	my->byte = (unsigned int)(((arr[3] & 0xff) << 0) | ((arr[4] & 0xff) << 8) | ((arr[5] & 0xff) << 16) | ((arr[6] & 0xff) << 24));
	my->d = (char) arr[7];
	
	print_values(my);
	free(my);
}

int main() {

	char a[] = {0x33, 0xcc, 0x1, 0xE8, 0x03, 0x00, 0x00, 0x5};
	my_func (a, sizeof(a));
	return 0;
}
