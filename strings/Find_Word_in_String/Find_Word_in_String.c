#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * AMAZON online test
 * operate func provides names of top "max_val" "keywords" in the "string" array that has max hits
 *
 * string - this can be the array of characters where search has to happen
 * str_size - total number of array
 * compete - the array of keywords
 * compete_size - size of keyword array
 * max_val - max keywords o/p to be printed
 *
 */
int isLetter(char ch)
{
	if ( (ch >= 'a' && ch <= 'z') ||  (ch >= 'A' && ch <= 'Z') )
		return 1;
	return 0;
}


int my_str_len(char *ch, int max)
{
	int i = 0;
	while (i < max)
	{
		if ( !isLetter(ch[i]) )
			break;		
		i++;
	}
	return i;
}

void operate (char *string[], int str_size, char *compete[], int compete_size, int max_val )
{
	int *count = (int*) calloc (sizeof(int ) * compete_size, 0) ;

	max_val = max_val > compete_size? compete_size: max_val;
	char *max_str[max_val];

	for(int comp_index = 0; comp_index < compete_size; comp_index++)
	{
		for (int str_index = 0; str_index < str_size; str_index++)
		{	
			for (int str_pos = 0; str_pos < (strlen(string[str_index]) - strlen(compete[comp_index])+1); str_pos++)
			{
				char letter_before = string[str_index][str_pos-1];
//				char letter_end = string[str_index][str_pos + strlen(compete[comp_index])];
				// start should be a word
				if ( (!str_pos || !isLetter(letter_before) )) 
				{
					int str_len = my_str_len ( string[str_index] + str_pos, strlen(string[str_index]) );
					int comp_len = strlen (compete[comp_index]) - 1;
					int len = str_len > comp_len ? str_len : comp_len;
					if(!strncasecmp(string[str_index] + str_pos, compete[comp_index], len))
					{
						count[comp_index]++;
						printf("\"%s\" match at index [%d] [%d]\n", compete[comp_index], str_index, str_pos);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i< compete_size; i++)
		printf("%d ", count[i]);

	printf("\n");
	for (int i = 0; i< max_val;)
	{
		int max = count[0];
		// Find max out of the lot
		for (int j = 0; j < compete_size; j++)
		{
			if (count[j] > max )
			{
				max = count[j];
			}
		}
		for (int j = 0; j < compete_size && i < max_val ; j++)
		{
			if (count[j] ==  max )
			{
				// add the max. also do this in case of multiple max value until i < max_val
				max_str[i] = ( (count[j]==0) ? NULL : compete[j] );
				i++;
				count[j]=-1;

			}
		}
	}
	for (int i = 0; i< max_val; i++)
	{
		if  (max_str[i] != NULL)
			printf("%s\n", max_str[i]);
		else
			printf("NULL\n");
	}
}

int main()
{
#if 0
	char *string[] = {"Anacell provides the best services in the city",
		"betacellular has awesome services",
		"Best services provided by anacell, everyone should use anacell"};
	char *compete[] = {"anacell", "betacellular"};
	operate (string, 3, compete, 2, 2 );
#elif 1
	char *string[] = {"I love anacell Best services; Best services provided by anacell",
		"betacellular has great services",
		"deltacellular provides much better services than betacellular",
		"cetracular is worse than anacell",
		"Betacellular is better than deltacellular."};
	char *compete[] = {"anacell", "betacellular","cetracular", "deltacellular", "eurocell"};
	operate (string, 5, compete, 5, 3 );
#elif 0
//	char *string[] = {"Anacell provides the best services in the city",
	char *string[] = {"Anaell provides the best services in the city",
		"anacell betacellular Anaell qkqanacell has awesome services",
		"Best services provided by anacell, everyone should use anacell"};
//	char *compete[] = {"anacell", "betacellular"};
	char *compete[] = {"ana", "betacellular"};
	operate (string, 3, compete, 2, 5 );
#endif
}
