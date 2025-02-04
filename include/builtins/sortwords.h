#ifndef SORTWORDS_H
#define SORTWORDS_H

#include <stddef.h>

int compare_words(const void *a, const void *b);
size_t read_words(const char *filename, char *words[], size_t max_words);
void free_words(char *words[], size_t word_count);
int sortwords(const char *input_file, const char *output_file);
int execute_sortwords_command(char **command_line_words, size_t num_args);


#endif // SORTWORDS_H