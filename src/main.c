#include <stdio.h>

int main(){

  #define MAX 100
  
  char user_input[100];
  printf("< ");
  fgets(user_input, MAX, stdin);
  printf("%s\n", user_input);

  return 0;

}
