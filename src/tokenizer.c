#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == ' ' || c == '\t') {
    return 1;
  }
  else {
    return 0;
  }
}

int non_space_char(char c){
  if (c != ' ' && c != '\t' && c != 0) {
    return 1;
  }
  else {
    return 0;
  }
}

char *token_start(char *str){
  while(*str != '\0' && space_char(*str)){
    str++;
  }
  return str;
}

char *token_terminator(char *str){
  while(non_space_char(*str)){
    str++;
  }
  return str;
}

int count_tokens(char *str){
  int count = 0;
  while(*str != '\0'){
    str = token_start(str);
    str = token_terminator(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
	char *copy = (char *)malloc((len + 1) * sizeof(char));
	for(int i = 0; i < len; i++){
		copy[i] = inStr[i];
	}
	copy[len] = '\0';
	return copy;
}

// An array of arrays
char **tokenize(char* str){
	int numTokens = count_tokens(str);
	char **tokens = malloc(sizeof(char*)*(numTokens + 1)); 
	// Creating an array for each token.  
	for(int i = 0; i < numTokens; i++){
		str = token_start(str);
		char *end = token_terminator(str);
		int length = end - str;
		tokens[i] = malloc(sizeof(char)*(length+1));
		char *copy = copy_str(str, length);
		for(int j = 0; j < length; j++){
			tokens[i][j] = copy[j];
		}
		tokens[i][length] = '\0';
		str = token_start(end);
	}
	return tokens;
}

void print_tokens(char **tokens){
	int i = 0;
	while(tokens[i] != NULL){
		printf("%s\n", tokens[i]);
		i++;
	}
}

void free_tokens(char **tokens){
	int i = 0;
	while(tokens[i] != NULL){
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
