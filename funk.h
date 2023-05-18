#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <limits.h>
#include <dirent.h>

//#include <stdint.h>

// struct dirent {
//   ino_t          d_ino;       /* inode number */
//   off_t          d_off;       /* offset to the next dirent */
//   unsigned short d_reclen;    /* length of this record */
//   unsigned char  d_type;      /* type of file; not supported
//                                  by all file system types */
//   char           d_name[256]; /* filename */
// };

enum {
    MaxLength = 500
};

int *prefix_function(const char *str);
void KMP(const char *text, const char *pattern, int line_number);
void print_prefix_function(const char *pattern);
int print_text(const char *input_text);
int KMP_search_in_file(const char *input_text, const char *pattern);
double wtime();
int KMP_search_in_dirent(const char *input_dir, const char *pattern);
int print_dirent(const char *input_dir);
int KMP_search_in_child_dirent(const char *input_dir, const char *pattern);
int KMP_search_in_dirent_without_recursion(const char *input_dir, const char *pattern);