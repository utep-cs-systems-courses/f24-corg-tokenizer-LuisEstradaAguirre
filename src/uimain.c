#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "history.h"
#include "tokenizer.h"

int main(){
	List *history = init_history();
	printf("Welcome!:\n");
	bool exit = false;
	
	while (!exit) {
		printf("Select an option: Add History (a), View History (v), Exit (e) \n");
		char option[30];
		fgets(option, sizeof(option), stdin);

		option[strcspn(option, "\n")] = '\0';

		if (strlen(option) == 1) {
			char choice = option[0];

			if (choice == 'a') {
				char str[100];
				printf("Enter string: ");
				fgets(str, sizeof(str), stdin);
				str[strcspn(str, "\n")] = '\0';
				add_history(history, str);
				printf("String added to history.\n");
			} 
			else if (choice == 'v') {
				if (history->root == NULL) {
					printf("There's no history!\n");
				} 
				else {
					printf("Full History\n");
					print_history(history);
					printf("Enter history ID to tokenize (e.g., !1) or any other key to return to the menu: ");
					char input[30];
					fgets(input, sizeof(input), stdin);
					input[strcspn(input, "\n")] = '\0'; 

					if (input[0] == '!') {
						int id = atoi(&input[1]);
						char *historyItem = get_history(history, id);
						if (historyItem) {
							printf("Tokenizing item: %s\n", historyItem);
							char **tokens = tokenize(historyItem);
							printf("Tokens:\n");
							print_tokens(tokens);
							free_tokens(tokens);
						} 
						else {
							printf("No item found with that ID.\n");
						}
					}
				}
			} 
			else if (choice == 'e') {
				exit = true;
				printf("Good Bye!\n");
			} 
			else {
				printf("Invalid option, please try again!\n");
			}
		} 
		else {
			printf("Invalid input! Please enter only a single character (a, v, or e).\n");
		}
	}
	free(history);
    return 0;
}
