#include"Node.h"
#include "projHeader.h"
/*
 * LinkedListed.c
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 *      Help from : Ira Shoemoe, Jeffery Zavala
 *      Tested on windows
 */


/*
 * This function first allocates memory for the new node being enqueued.
 * duplicates the string into data.
 * then sets the newNodes next to null .
 * it then checks if the list has no element by asking if head is null
 * if it is then the data is just head refers to the new node.and head is returned
 * if it does have something in it. A temp node is created to traverse the list and
 * places the element at the end when found.
 */
struct Node* enqueue(struct Node *head, char *s)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = strdup(s);
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
		return head;
	}

	struct Node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}
/*
 * The push method works similar to the enqueue method in that it first allocates
 * memory for the node being added. duplicates the string to be added into the nodes data field.
 * Then sets the next field to null. Checks if the list is empty,
 * if it is the head points to the newly created struct Node.
 * if not then the newNodes next field points to head and head now refers to
 * the new node.
 * head is return to retrun the original linked list because the fuction makes a copy.
 */

struct Node* push(struct Node *head, char *s)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = strdup(s);
	newNode->next = NULL;
	if(head == NULL)
		head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}
	return head;
}

/*
 * printlist fuction first asks if the list is empty by asking if head is = to null
 * if it is it prints that the list is empty
 * if not then it creates a temp node to refer to head. loops through
 * list and prints the data at each point
 */

void printlist(struct Node *head)
{
	if(head == NULL)
	{
		printf("The List is Empty\n");
	}
	else
	{
		struct Node *temp = head;
		while(temp != NULL)
		{
			printf("%s\n", temp->data);
			temp = temp->next;
		}
	}
}
/*
 * This fuction creates a temp node to refer to head to null values store in the list as you
 * delete the links from head. The loop goes until head is equal to null.And temp is freed at
 * the end to allow for the memory to be used elsewhere.
 */
struct Node* deletelist(struct Node *head)
{
	struct Node *temp = head;
	while(head != NULL)
	{
		head = head->next;
		temp->next = NULL;
		temp->data = 0;
		free(temp);
		temp = head;
	}
	head = NULL;
	return head;
}

/**
 * Two nodes are made. One to keep track of the previous and one to keep track of the next.
 * If head is the node we want to delete , then we move the head to the next and delete the node using the pointer to
 * head. The loop goes until heads next is equal to null to find a match. If we do find
 * a match the a new node is created at temp.temp2 is then set to temps next, and set temp to temp2s next so the list
 * stays connected. delete the node at the new node. if not equal , move prev to temp and move temp to temp next
 * return head
 */
struct Node* deleteNode(struct Node *head, char *s)
{

	struct Node *temp = head->next;
	struct Node *temp2 = head;
	if(mystrcmp(temp2->data, s))
	{
		head = head->next;
		temp2->next = NULL;
		temp2->data = 0;
		free(temp2);
	}
	while(temp != NULL)
	{
		if(mystrcmp(temp->data, s))
		{
			struct Node *delete = temp;
			temp2->next = temp->next;
			temp = temp2->next;
			delete->next = NULL;
			delete->data = 0;
			free(delete);
		}
		else{
			temp2 = temp;
			temp = temp->next;
		}
	}
	return head;
}







