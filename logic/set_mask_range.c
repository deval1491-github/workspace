#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 31;
	int b = 2;
//	int mask = (1 << (a+1)) - (1 << b) ;
	int m = ((1 << a) - 1) * 2 + 1 ;
//	m = (m << 1) + 1;
	m = m - ( (1<<b) - 1);
	printf("0x%08x\n", m);
	int mask = (1 << a) - (1 << b) ;
	printf("0x%08x\n", mask);

int bits = a - b + 1;
bits = (1 << bits) - 1;
printf("0x%08x\n", bits);
bits = bits << b;
printf("0x%08x\n", bits);

	return 0;
}
