#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list =  malloc(sizeof(List));
  list -> root = NULL;
  return list;
}

void add_history(List *list, char *str){
	Item *item = malloc(sizeof(Item));
	item -> next = NULL;
	
	int strLength = 0;
	while(str[strLength] != '\0'){
		strLength++;
	}
	
	item -> str = malloc(strLength + 1);
	item->str = copy_str(str, strLength);

	
	if(list -> root == NULL){
		item -> id = 1;
		list -> root = item;
	}
	else{
		Item *curr = list->root;
		while (curr->next != NULL) {
			curr = curr -> next;
		}
		item -> id = (curr -> id) + 1;
		curr -> next = item;
	}
}

char *get_history(List *list, int id){
	Item *curr = list -> root;
	int counter = 1;
	while(counter < id){
		curr = curr -> next;
		counter ++;
		if(curr == NULL){
			printf("Invalid ID");
			break;
		}
	}
	return curr -> str;
	
}

void print_history(List *list){
	Item *curr = list -> root;
	while(curr != NULL){
		printf("%d. %s\n", curr -> id, curr -> str);
		curr = curr -> next;
	}
}

void free_history(List *list) {
    Item *curr = list->root;
    while (curr != NULL) {
        Item *next = curr->next;
        free(curr->str);  // Free the memory for the string
        free(curr);       // Free the memory for the item itself
        curr = next;
    }
    free(list);  // Finally, free the list structure itself
}

//~ int main(){
	//~ // Initialize the history list
    //~ List *history = init_history();
    
    //~ // Add some history items
    //~ add_history(history, "Hello");
    //~ add_history(history, "World");
    //~ add_history(history, "Miaw");
    //~ add_history(history, "Mi");
    //~ add_history(history, "Mama");
    
    //~ // Print the entire history
    //~ printf("Full history:\n");
    //~ print_history(history);

    // Get and print specific history items by id
    //~ printf("\nRetrieving history item with ID 2:\n");
    //~ char *historyItem = get_history(history, 2);
    //~ if (historyItem) {
        //~ printf("Item: %s\n", historyItem);
    //~ } else {
        //~ printf("No item found with that ID.\n");
    //~ }
//~ }
