#ifndef TOKENIZER_H
#define TOKENIZER_H

/* tokenizer API */
int space_char(char c);
int non_space_char(char c);
char *token_start(char *s);
char *token_terminator(char *token);
int count_tokens(char *s);
char *copy_str(char *inStr, short len);
char **tokenize(char *s);
void print_tokens(char **tokens);
void free_tokens(char **tokens);

/* tester compatibility wrappers */
int string_length(char *s);
int is_valid_character(char c);
char *find_word_start(char *s);
char *find_word_terminator(char *s);
int count_words(char *s);

#endif /* TOKENIZER_H */
