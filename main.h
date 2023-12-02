#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_args(ssize_t chars_num, char *input_ptr);
void print_env(const char *cmnd);

#endif /* MAIN_H */
