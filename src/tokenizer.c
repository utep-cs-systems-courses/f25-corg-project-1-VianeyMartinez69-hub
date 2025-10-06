#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
    return (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
    return (c != '\0' && !space_char(c));
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str) {
    while (*str && space_char(*str)){
        str++;
    }
    return (*str) ? str : 0;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token) {
    while (*token && non_space_char(*token)){
        token ++;
    }
    return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str) {
    int count = 0;
    char *tok = token_start(str);

    while (tok){
        count ++;
        tok = token_start(token_terminator(tok));
    }
    return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    char *copy = malloc((len + 1) * sizeof(char));
    if (!copy) return 0;

    strncpy(copy, inStr, len);
    copy[len] = '\0';
    return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str) {
    int n = count_tokens(str);
    char **tokens = malloc((n + 1) * sizeof(char*));
    if (!tokens) return 0;

    int i = 0;
    char *tok = token_start(str);

    while (tok ){
        char *end = token_terminator(tok);
        int len = end - tok;
        tokens[i++] = copy_str(tok, len);
        tok = token_start(end);
    }
    tokens[i] = 0;
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
    for (int i = 0; tokens[i] != 0; i++){
        printf("%s\n", tokens[i]);
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
    if(!tokens) return;
    for (int i = 0; tokens[i] != 0; i++){
        free(tokens[i]);
    }
    free(tokens);
}
int string_length(char *s) {
  int n = 0;
  if (!s) return 0;
  while (s[n] != '\0') n++;
  return n;
}

int is_valid_character(char c) {
  // tester expects: space => 0, letters => 1
  return non_space_char(c);
}

char *find_word_start(char *s) {
  return token_start(s);
}

char *find_word_terminator(char *s) {
  return token_terminator(s);
}

int count_words(char *s) {
  return count_tokens(s);
}
