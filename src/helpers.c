#include "malloc.h"
#include "tokenizer.h"

// True if c is a tab or space, and not zero
int space_char(char c){

  if(c == '\t' || c == ' ')
    return 1;

  else
    return 0;

}

// True if c is not a tab or space, and not zero
int non_space_char(char c){

  if(c != '\t' && c != ' ')
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

// The number of words in str
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

// Allocates some space for the words it copies
char *copy_str(char *inStr, short len){

  char * pointer = malloc(len + 1); //must allocate extra space for zero('\0') terminator
  
  int i;
  for(i = 0; i <= len; i++)
    pointer[i] = inStr[i]; // copies character into new string

  pointer[len] = '\0'; // breaking zero
  return pointer;  
  
}

// All tokens will be printed
void print_tokens(char **tokens){
  int i = 0;
  while(*tokens){

    printf("%s\n", tokens[i]);
    tokens++;
    
  }
  
}

// Frees all tokens and uses free() to release memory
void free_tokens(char **tokens){

  while(*tokens){

    free(*tokens);
    tokens++;

  }
  free(tokens);
  
}
