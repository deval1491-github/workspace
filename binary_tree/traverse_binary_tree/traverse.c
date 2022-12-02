#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct Node {
	int data;
	struct Node *next;
} node ;

node *create_node(int data) {
	
}


int main ()
{
	node *root = NULL;
	root = create_node ();
	printf("%ld\n",sizeof(node));	
	return 0;
}
