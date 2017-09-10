#include <stdio.h>
#include "list.h"

struct node *create(int v) {
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->next = NULL;
	new->value = v;
	return new;
}

void append(struct node *root, int v) {
	struct node *curr = root;
	while(curr->next) {
		curr = curr->next;
	}
	curr->next = (struct node *) malloc(sizeof(struct node));
	curr->next->value = v;
	curr->next->next = NULL;
}

void print(struct node *root) {
	struct node *curr = root;
	while(curr) {
		printf("%d -> ", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

void free_list(struct node *root) {
	struct node *curr, *prev;
	curr = root;
	while(curr) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}

struct node *prepend(struct node *root, int value) {
	struct node *curr = root;
	struct node *newNode = malloc(sizeof(struct node));
	
	if(curr->next == NULL) {
		newNode->value = value;
		curr->next = newNode;
		newNode ->next = NULL;
	}else {
		newNode->next = curr->next;
		newNode->value = value;
		curr->next = newNode;
	}	
	
}

int get(struct node *root, int index) {
	struct node *curr = root;
    int count = 0; 
    while (curr != NULL) {
       if (count == index)
          return(curr->value);
       count++;
       curr = curr->next;
    }
   
}

void add(struct node *root, int index, int value) {
	struct node *curr = root;
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	
	temp->value = value;
	
	if(index == 0) {
		temp->next = curr;
		curr = temp;
		return;
	}
	
	struct node *temp2 = curr;
	
	for(int i = 0; i < index - 2; i++) {
		temp2 = temp2->next;
	}
	
	temp->next = temp2->next;
	temp2->next = temp;
	
}

void remove_node(struct node *root, int index) {
	struct node *curr = root;
	struct node *temp;
	int count = 0;
	
	while(curr != NULL) {
		if(count == index) {
			temp = curr->next;
			curr->value = temp->value;
			curr->next = temp->next;
			free(temp);
		}
		count++;
		curr = curr->next;			
	}
}

int find(struct node *root, int value){
	struct node *curr = root;
	struct node *temp;
	int count = 0;
	
	while(curr != NULL) {
		if(curr->value == value)
			return count;
		count++;
		curr = curr->next;
	}
}

int main() {
	struct node *list = create(0);
	
	append(list, 1);
	print(list);
	
	append(list,2);
	append(list,3);
	append(list,4);
	print(list);
	
	prepend(list, 6);
	print(list);
	
	printf("Element at index 3 is %d\n", get(list, 3));
	printf("Element 3 is at index %d\n", find(list, 3));
	
	add(list, 3, 8);
	print(list);
	
	remove_node(list, 3);
	print(list);
	
	free_list(list);
	
	return 0;

}