#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include "history.h"
#include "tokenizer.h"


// Initializes the linked list
List *init_history(){

  List *list = malloc(sizeof(List));
  list-> root = malloc(sizeof(Item));
  return list;

}

// Add a history item to the end of the list
void add_history(List *list, char *str){

  List *tempo = list;
  Item *n_item;
  n_item = tempo-> root;
  

  //n_item-> id = 0;
  // n_item-> str = tempo-> root;
  //tempo-> = n_item;

  //if(tempo-> root-> next != 0){

  //tempo-> root = tempo-> root-> next;
    while(n_item-> next != 0)

      n_item = n_item-> next;
    

    n_item-> next = malloc(sizeof(Item));
    n_item-> next-> id = n_item-> id++;
    n_item-> next-> str = str;

    if(list-> root-> str == 0)
      list-> root = list-> root = list-> root-> next;


}

// Retrieve the string stored in the node where Item->  == id
char *get_history(List *list, int id){

  Item *pr = malloc(sizeof(Item));
  pr = list-> root;

  if(list == 0 && list-> root == 0)
    return 0;
  
  
  while(pr != 0){
    if(pr-> id == id)
      return pr-> str;

    pr = pr-> next;
  }
  return 0;

}

// Print the contents of the list
void print_history(List *list){

  Item *now = list-> root;

  while(now != 0){           // not equal to null
    printf("Contents of the list: %s\n", now-> str);
    now = now-> next;
}

// Free the history list and the strings it references
void free_history(List *list){

  Item *now = list-> root;

  while(now != 0){

    Item *following = now-> next;   

    // free memory after contents have been printed
    free(now-> str);
    free(now);

    now = following;

  }
}
}

