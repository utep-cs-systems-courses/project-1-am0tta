#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100

void initiate_input(char c);
int main(){
  
  //Building a simple UI with fgets() - Milestone 1
  char user_input[100];
  printf("Welcome.\n");
  printf("Enter your sentence. When you are ready to quit simply type 0.\n");
  printf("< ");
  fgets(user_input, MAX, stdin);
  
  //exit() function to end the program
  if(user_input[0] == '0'){
  printf("\n");
  printf("Goodbye\n");
    exit(0);
  }
  
  printf("%s\n", user_input);

  
  //The program keeps going until the user types 0
  if(user_input[0]!= '0'){
    int keepUp = main();
  }
  return 0;
}
