#include <stdio.h>
#include <stdlib.h>

// Doubly Linked LIst

typedef struct node node;

struct node{
	int data;
	node* next;
	node* prev; 
};

void insert(node* current, int data){
	
	node* inserted = (node*)malloc(sizeof(node));
	inserted->next = current->next;
	current->next = inserted;
	inserted->prev = current;
	inserted->data = data;

}

node* grabPosition(node* current, int position){

	int i = 0;
	for(i = 0; i < position; i++)
	{
		current = current->next;
	}
	return current; 
}


void append(node* current, int data){

	while(current->next != NULL)
		current = current->next;
	node* tail = (node*)malloc(sizeof(node)); 
	current->next = tail;
	tail->data = data;
	tail->prev = current;
	tail->next = NULL;

}

void delete(node* current, int data){

	while(current->data != data)
	{
		current = current->next;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev; 
	free(current);
	
}

void print(node* current){

	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->next; 
	}
	printf("NULL \n");
}

int main(){
	
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL; 
	head->prev = NULL; 
	head->data = 1; 

	append(head, 2);
	append(head, 3);
	append(head, 4); 
	print(head);

	delete(head, 3);
	print(head);

	insert(grabPosition(head, 1), 7); 
	print(head);

	return 0; 

}