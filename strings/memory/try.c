/* snprintf example */
#include <stdio.h>

int main ()
{
	char buffer [100];
	int cx;
	volatile int a = *((int*)0x100);
	printf("%x\n", a);
#if 0
	cx = snprintf ( buffer, 100, "The half of %d is %d", 60, 60/2 );

	if (cx>=0 && cx<100)      // check returned value

	snprintf ( buffer+cx, 100-cx, ", and the half of that is %b .", 60/2/2 );

	puts (buffer);


printf("%b\n",0xf);
#endif
	return 0;
}
