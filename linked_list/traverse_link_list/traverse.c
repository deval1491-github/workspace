#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct Link_List {
	int data;
	struct Link_List *next;
} ll ;

void create_node_at_end(ll **root, int data) {
	ll *p1 = *root, *temp = (ll*) malloc (sizeof(ll));
	temp->data = data;
	temp->next = NULL;
	if(*root == NULL)
		*root = temp;
	else {
		while(p1->next != NULL)
			p1 = p1->next;
		p1->next = temp;
	}	
}
void add_node_at_start(ll **root, int data) {
	ll *p1 = *root, *temp = (ll*) malloc (sizeof(ll));
	temp->data = data;
	temp->next = *root;
	*root = temp;
}
void traverse(ll *root) {
	ll *p1 = root;
	while(p1 != NULL) {
		printf("%d -> ", p1->data);
		p1 = p1->next;
	}
	printf("\n");
}
void reverse(ll *root, ll **head_ref) {
	if (root == NULL) return;
	ll *p1 = root, *p2 = root->next;
	if (root->next == NULL) {
		*head_ref = root;
		return;
	}
	else {
		reverse(p1->next, head_ref);
		p2->next = p1;
		p1->next = NULL;
	}
}
void  delete (ll **node, int data) {
	if ((*node) == NULL) {
		printf("%s: NULL detected\n", __func__);
		return;
	}
	ll *p1 = (*node), *p2 = p1->next;
	if (p1->data  == data) {
		printf("found at head\n");
		*node = (*node)->next;
		free(p1);
		return; 	
	}
	while(p2 !=NULL) {
		if(p2->data == data) {
			printf("found \n");
			p1->next = p2->next;
			free(p2);
			return;
		}
		p1 = p1->next;
		p2 = p1->next;
	}
	printf ("NODE with data  = %d not found\n", data);
}
int main ()
{
	ll *list1 = NULL;
	delete(&list1, 0);
	traverse(list1);
	add_node_at_start (&list1, 0);
	traverse(list1);
	delete(&list1, 0);
	traverse(list1);
	create_node_at_end (&list1, 1);
	create_node_at_end (&list1, 2);
	reverse(list1, &list1);
	create_node_at_end (&list1, 3);
	
	traverse(list1);
	add_node_at_start (&list1, -1);
	traverse(list1);
	delete(&list1, 3);
	traverse(list1);
	return 0;
}
