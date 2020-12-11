#include "Node.h"
#include "projHeader.h"
/*
 * projMain.c
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 *      Help from : Ira Shoemoe, Jeffery Zavala
 *      tested on windows
 */


	int main(int argc, char* argv[])
	{

		struct Node *headq = NULL;
		struct Node *heads = NULL;
		char s[3] = " \n";
		char *s2;
		int counter = 0;
		int lineCounter = 0;
		int nLines = 0;
		int delete = 0;

		for(int i = 0; i < argc - 1; i++)
		{
			if(mystrcmp(argv[i], "-f"))// check -f to see if i need to read the file
				counter = i;
			if(mystrcmp(argv[i], "-n"))//check -n to see how many lines there are by adding 1
				lineCounter = i;
			if(mystrcmp(argv[i], "-d"))//check if -d is there to see if i need to delete a word
				delete = i;
		}
		if(mystrcmp(argv[counter], "-f") == true)
		{
			char buff[80];
			FILE *fp = fopen(argv[counter + 1],"r");
			if(lineCounter != 0)
			{
				while((fgets(buff, 80, fp) != NULL) &&  nLines < atoi(argv[lineCounter + 1]))
				{
					s2 = strtok(strdup(buff),s);
					while(s2 != NULL)
					{
						headq = enqueue(headq, s2);
						heads = push(heads, s2);
						s2 = strtok(NULL, s);
					}
					nLines++;
				}
			}
			else{
				while((fgets(buff, 80, fp) != NULL))
				{
					s2 = strtok(strdup(buff),s);
					while(s2 != NULL)
					{
						headq = enqueue(headq, s2);
						heads = push(heads, s2);
						s2 = strtok(NULL, s);
					}
				}
			}
		}
		else
		{
			char buff[80];
			if(lineCounter != 0){
				while(nLines < atoi(argv[lineCounter + 1]) && (fgets(buff, 80, stdin) != NULL))
				{
					s2 = strtok(strdup(buff),s);
					while(s2 != NULL)
					{
						headq = enqueue(headq, s2);
						heads = push(heads, s2);
						s2 = strtok(NULL, s);
					}
					nLines++;
				}
			}
			else{
				while((fgets(buff, 80, stdin) != NULL))
				{
					s2 = strtok(strdup(buff),s);
					while(s2 != NULL)
					{
						headq = enqueue(headq, s2);
						heads = push(heads, s2);
						s2 = strtok(NULL, s);
					}
				}
			}
		}
		if(delete != 0)
		{
			printf("This is the queue list: \n");
			printlist(headq);
			printf("This is the stack list: \n");
			printlist(heads);
			heads = deleteNode(heads, argv[delete + 1]);
			headq = deleteNode(headq, argv[delete + 1]);
		}

		printf("This is the queue list: \n");
		printlist(headq);
		printf("This is the stack list: \n");
		printlist(heads);
		heads = deletelist(heads);
		headq = deletelist(headq);
		printf("This is the queue list after deletion: \n");
		printlist(headq);
		printf("This is the stack list after deletion: \n");
		printlist(heads);
		if(heads == NULL)
			printf("headq is null\n");
		if(headq == NULL)
			printf("headq is null");

//
   return 0;

}
