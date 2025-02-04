#ifndef ALIAS_H
#define ALIAS_H

#include "../config.h"

#include <pthread.h>
#include <stddef.h>

#define TABLE_SIZE 100
#define MAX_ALIAS_LENGTH 256

typedef struct AliasEntry {
    char alias[MAX_ALIAS_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    struct AliasEntry *next;
} AliasEntry;

typedef struct {
    AliasEntry *table[TABLE_SIZE];
    pthread_mutex_t mutex;
} AliasTable;

extern AliasTable alias_table;

unsigned int hash(const char *str);
int add_alias(const char *alias, const char *command);
const char* get_command_for_alias(const char *alias);
void remove_quotes(char *str);
void print_aliases();
char* concatenate_args(char **command_line_words, size_t num_args);
int remove_alias(const char *alias);
int execute_alias_command(char **command_line_words, size_t num_args);


#endif // ALIAS_H
