#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100

void initiate_input(char c);
int main(){

  //List *hist = init_history();
  
  // Building a simple UI with fgets()
  char user_input[100];
  printf("\n");
  printf("Welcome.\n");
  printf("Enter your sentence. When you are ready to quit simply type 0.\n");
  printf("< ");
  fgets(user_input, MAX, stdin);
  
  // exit() function to end the program
  if(user_input[0] == '0'){
    
    printf("\n");
    printf("Goodbye :)\n");
    exit(0);
    
  }
  
  printf("%s\n", user_input);

  // if(user_input[0] == '1'){

  // add_history(hist, user_input);
    
  // }

  // testing word_start
  char *p = word_start(user_input);
  printf("Word starts at: %s\n", p);

  // testing word_terminator
  char *po = word_terminator(user_input);
  printf("Word ends at: %s\n", po);
  
  // testing count_words
  int words = count_words(user_input);
  printf("The number of words is: %d\n", words);
  printf("\n");
  
  // testing print_tokens
  char **tokens = tokenize(user_input);
  printf("Here are the tokens: \n");
  print_tokens(tokens);

  // free tokens
  free_tokens(tokens);
  
  // The program keeps going until the user types 0
  if(user_input[0]!= '0'){
    int keepUp = main();
  }

  //print_history(hist);
  //free_history(hist);
  
  return 0;
}
