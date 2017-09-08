#include <stdio.h>
#include <stdlib.h>
#include "media.h"

#define MEDIA_LIST_SZ 100

int main(int argc, char* argv[]) {
	printf("Welcome to Flix\n");

	struct media media_list[MEDIA_LIST_SZ];
	int count = 0;

	struct media* m;
	media_list[0].name = "Rick and Morty";
	media_list[1].name = "Game of Thrones";
	media_list[2].name = "Black Mirror";

	//initialize playlist
	struct linked_list* play_list;
	play_list = (struct linked_list*)malloc( sizeof(struct linked_list) );
	
	if(play_list == NULL) {
		printf("Failed to allocate memory\n Exiting\n");
		exit(1);
	}

	play_list->head = NULL;

	struct ll_node* n1;
	struct ll_node* n2;
	struct ll_node* n3;
	struct ll_node* n;

	n1 = (struct ll_node*)malloc( sizeof(struct ll_node) );
	
	if(n1 == NULL) {
		printf("Failed to allocate memory\n Exiting\n");
		free(play_list);
		exit(1);
	}

	n1->next = NULL;
	n1->data = NULL;

	n1->data = media_list + 2;

	n2 = (struct ll_node*)malloc( sizeof(struct ll_node) );

        if(n2 == NULL) {
                printf("Failed to allocate memory\n Exiting\n");
                free(play_list);
		free(n1);
                exit(1);
        }

        n2->next = NULL;
        n2->data = NULL;

        n2->data = media_list + 1;

	n3 = (struct ll_node*)malloc( sizeof(struct ll_node) );

        if(n3 == NULL) {
                printf("Failed to allocate memory\n Exiting\n");
                free(play_list);
		free(n1);
		free(n2);
                exit(1);
        }

        n3->next = NULL;
        n3->data = NULL;

        n3->data = media_list + 0;

	n1->next = n2;
	n2->next = n3;
	play_list->head = n1;

	for(n = play_list->head; n != NULL; n = n->next) {
		struct media* m = (struct media*) n->data;
		printf("%s\n", m->name);
//add counter in here for length
	}

	free(n1);
	free(n2);
	free(n3);
	free(play_list);
	return 0;
}
