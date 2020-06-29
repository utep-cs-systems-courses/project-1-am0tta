#include "malloc.h"
#include "tokenizer.h"

// True if c is a tab or space, and not zero
int space_char(char c){

  if(c == '\t' || c == ' ')
    return 1;                 // true, since C does not handle boolean variables

  else
    return 0;                // false

}

// True if c is not a tab or space, and not zero
int non_space_char(char c){

  if(c != '\t' && c != ' ')    
    return 1;                // 1 stands for true in C

  else
    return 0;               // 0 stands for false in C
  
}

// pointer to first (non-space) char in first word in str
char *word_start(char *str){
  
  while(*str){           //while something is here
    
    if(non_space_char(*str))
      return str;
    
    *str++;
  }
  return 0;

}

// pointer to char after end of word
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

  char * pointer = malloc(len + 1); //must allocate extra space for zero ('\0') terminator
  
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
  free(*tokens);
  
}

/* Returns a freshly allocated vector of freshly allocated
   space-separated tokens from zero terminated str. */
char **tokenize(char *str){

  int i;
  //char *original = str;                 // pointer to keep an eye on the provided string
  int words = count_words(str);
  char **tokens = malloc (sizeof(char *) *(words + 1));
  char *final = word_terminator(str);         //pointer at the end

  for(i = 0; i < words-1; i++){

    str = word_start(str);
    //original = word_start(original);
    //final = word_terminator(original);
    
    
    int length = word_terminator(str) - str;    // lenght difference
    tokens[i] = copy_str(str,length);

    str = word_terminator(str);                // points to available next word

  }

  tokens[i] = '\0';
  return tokens;
  
}
