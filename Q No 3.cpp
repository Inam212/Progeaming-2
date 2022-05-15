#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

int countOfNodes(Node* head)
{
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}

Node* deleteMid(Node* head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL) {
		free(head);
		return NULL;
	}
	Node* copyHead = head;
	int count = countOfNodes(head);
	int mid = count / 2;
	head = head->next;
	head->next = head->next->next;
	return copyHead;
}

void printList(Node* ptr)
{
	while (ptr != NULL) {
		printf("%d ->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

Node* newNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}


int main()
{
	
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	printf(" Linked List\n");
	printList(head);
	head = deleteMid(head);
	printf("Update Linked List \n");
	printList(head);
	return 0;
}


