#include "malloc.h"
#include "tokenizer.h"

//true if c is a tab or space, and not zero
int space_char(char c){

  if (c == '\t' || c == ' ')
    return 1;

  else
    return 0;

}

//true if c is not a tab or space, and not zero
int non_space_char(char c){

  if (c != '\t' && c != ' ')
    return 1;

  else
    return 0;
  
}

// * to first (non-space) char in first word in str
char *word_start(char *str){
  
  while(*str){           //while something is here
    
    if(non_space_char(*str))
      return str;
    
    *str++;
  }
  return 0;

}

// * to char after end of word
char *word_terminator(char *word){

  while(*word){           //while something is here

    if(space_char(*word))
      return word;

    else if(non_space_char(*word))
      *word++;
    
  }
  return 0;
}

// the number of words in str
int count_words(char *str){

  int num_words = 0;
  int position = 0;

  while(*str){
    if(non_space_char(*str) && position == 0){

      position = 1;
      num_words++;
    }
    else if(space_char(*str) && position == 1)
     position = 0;
 
    *str++;
    
  }
  return num_words;
}

char *copy_str(char *inStr, short len){
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}
