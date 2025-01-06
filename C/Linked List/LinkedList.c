/* C program by arsalan Kataneh for CS 1311 ,
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct item{ /*hold information about things */
			char name [50];
			double value; 
			struct item *next;			
			};
struct item *start, *ptemp, *current; 			




void main (void)
{
	printf("This program shows things I want. \n\n");
	
	current = malloc (sizeof(struct item)); // create first record 
	strcpy (current->name, "rolex");
		current->value = 70000;
		current->next = NULL;
		ptemp = current; // point to last finished item 
		start = current;
	
	current = malloc(sizeof(struct item));  /* create second record*/
	strcpy (current->name, "house");
	current->value = 4500000; 
	current->next = NULL;
	ptemp->next = current; /* point last element */
	ptemp = current;
	
	current = malloc(sizeof(struct item));  /* create second record*/
	strcpy (current->name, "car");
	current->value = 100000; 
	current->next = NULL;
	ptemp->next = current; /* point last element */
	ptemp = current;
	
	current = malloc(sizeof(struct item));  /* create second record*/
	strcpy (current->name, "company");
	current->value = 1000000000; 
	current->next = NULL;
	ptemp->next = current; /* point last element */
	ptemp = current;
	
current = start; 
printf("\n ITEM NAME                 $ VALUE \n");
while(current != NULL) // print eaxh reccord 
	 {
	  printf (" %-18s        $%.0lf \n", current->name, current->value);
	  current = current->next; // go to the next record 
	 }

}
