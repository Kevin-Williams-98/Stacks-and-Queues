#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
/*
 * Node.h
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 *      Help from : Ira Shoemoe, Jeffery Zavala
 *      tested on windows
 */

#ifndef Node_H_
#define Node_H_

struct Node
{
    // Any data type can be stored in this Node
    char  *data;

    struct Node *next;
};
struct Node* enqueue(struct Node *head, char *s);
struct Node* push(struct Node *head, char *s);
void printlist(struct Node *head);
struct Node* deletelist(struct Node *head);
struct Node* deleteNode(struct Node *head, char *s);



#endif /* Node_H_ */
