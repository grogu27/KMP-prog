#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <limits.h>

//#include <stdint.h>

enum {
    MaxLength = 500
};

int *prefix_function(const char *str);
void KMP(const char *text, const char *pattern, int line_number);
void print_prefix_function(const char *pattern);
int print_text(const char *input_text);
int KMP_search_in_file(const char *input_text, const char *pattern);
double wtime();