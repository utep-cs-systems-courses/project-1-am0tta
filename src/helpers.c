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

  if (c >= 34 && c <= 126)
    return 1;

  else
    return 0;
  
}

// * to first (non-space) char in first word in s
char word_start(char *str){

}

// * to char after end of word
char *word_terminator(char *word){
}

// the number of words in s
int count_words(char *str){
}

char *copy_str(char *inStr, short len){
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}
