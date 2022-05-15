#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
};


void swapNodes(struct Node** head_ref, int x, int y)
{
	
	if (x == y)
		return;

	
	struct Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}

	
	struct Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}

	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else 
		*head_ref = currY;

	if (prevY != NULL)
		prevY->next = currX;
	else 
		*head_ref = currX;

	struct Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* start = NULL;

	
	push(&start, 9);
	push(&start, 8);
	push(&start, 7);
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);

	printf("\n Linked list before calling: ");
	printList(start);

	swapNodes(&start, 3, 9);

	printf("\n Linked list after calling: ");
	printList(start);

	return 0;
}

