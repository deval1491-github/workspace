#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fortinet

char *old = NULL;

char* my_strtok (char *string, const char *s) {

	int i = 0;
	if (string == NULL)
		string = old;

	char *ptr = string;
	if (ptr == NULL)
		return NULL;
	
	while (*ptr == *s && *ptr != '\0')
		ptr++;

	for (; i < strlen(ptr); i++)
		if(ptr[i] == *s)
			break;

	if (i == 0)
		return NULL;
	ptr[i] = 0;
	old = ptr + i + 1;
	return ptr;
}
int main()
{
	char string[20] = "--this is -Deval";
//	char string[20] = "--this--";
//	char string[20] = "";
	char s[2] = "*";
//	char *token = my_strtok (NULL, s);
	char *token = my_strtok (string, s);
	if(token != NULL)
		printf("%s\n", token);

	token = my_strtok (NULL, s);
	if(token != NULL)
		printf("%s\n", token);
	
char string2[20] = "--this is - Deval";
char* my = strtok(string2, s);
//char* my = strtok(NULL, s);
printf("--> %s\n", my);
	return 0;
}
