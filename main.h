#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_NO 20

extern char **environ;

/* Memory Helpers */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_arr(char **arr);
void free_str(char *str);

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
int _atoi(const char *str);
int _isalpha(int c);
void rev_string(char *s);
char *_itoa(int n);
char *_strstr(char *haystack, char *needle);
char *_strtok(char *str, const char *delimiter);

/* Main Tasks */
char **get_args(ssize_t chars_num, char *input_ptr, const char *delimiter);
char **initiate_env();
void print_env(char **temp_env);
void update_env(char ***env, char **current_env, char *var, char *val);
void add_env(char ***env, char **current_env, char *var, char *val);
void set_env(char ***env, char *var, char *val);
int get_index(char **env, char *var);
char **remove_index(char **env, int index);
int unset_env(char ***env, char *var);
char *get_env(char **env, char *var);
int _cd(char ***env, char **arr);
char **initiate_aliases();
void _alias(char ***aliases, char **arr);
ssize_t remove_comments(char *str);
ssize_t _getline(char **inputptr, size_t *num, FILE *buff_type);
int handle_builtin(char ***new_env, char ***new_aliases, char **arr);
char *check_path(char **arr);
int exec_cmnds(char ***new_env, char **arr);
int he_exit(char **arr);
void handle_vars(char ***new_env, char **arr, int ex_status);
char *get_separator(char *str);
void handle_semicolon(char ***new_env, char ***new_aliases,
		char **args, char **arr);
void handle_AND(char ***new_env, char ***new_aliases,
		char **args, char **arr);
void handle_OR(char ***new_env, char ***new_aliases,
		char **args, char **arr);
void handle_separator(char ***new_env, char ***new_aliases,
		char **args, char **arr, char *separator);

#endif /* MAIN_H */
