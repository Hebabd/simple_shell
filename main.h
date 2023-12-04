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
void free_arr(char **arr);

/* String Helpers */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
char *_strtok(char *str, const char *delimiter);

/* Main/Task Functions */
char **get_args(ssize_t chars_num, char *input_ptr);
char **initiate_env();
void print_env(char **temp_env, char *cmnd);
void update_env(char ***env, char **current_env, char *var, char *val);
void add_env(char ***env, char **current_env, char *var, char *val);
void set_env(char ***env, char *var, char *val);
int get_index(char **env, char *var);
char **remove_index(char **env, int index);
int unset_env(char ***env, char *var);
ssize_t remove_comments(char *str);
ssize_t _getline(char **inputptr, size_t *num, FILE *buff_type);

#endif /* MAIN_H */
