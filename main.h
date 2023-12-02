#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/* Memory Helpers */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* Main/Task Functions */
char **get_args(ssize_t chars_num, char *input_ptr);
void print_env(const char *cmnd);
ssize_t _getline(char **inputptr, size_t *num, FILE *buff_type);

#endif /* MAIN_H */
