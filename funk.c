#include "funk.h"

int *prefix_function(const char *str) 
{
    int *pref = malloc(sizeof(int) * strlen(str));

    if (!pref)
        return NULL;

    if (strlen(str) == 0)
    {
        printf("Длина подстроки равна нулю\n");
        free(pref);
        return 0;
    }
    pref[0] = 0;
    int j = 0;
    for (int i = 1; i < strlen(str); i++)
    {
        while (j > 0 && str[j] != str[i])
            j = pref[j - 1];
        if (str[j] == str[i])
            j++;
        pref[i] = j;
    }
    return pref;
}

void KMP(const char *text, const char *pattern, int line_number)
{
    int len_text = strlen(text);
    int len_pattern = strlen(pattern);
    int *prefix = prefix_function(pattern);
    int i = 0; //позиция в строке
    int j = 0; //позиция в подстроке
    while (i < len_text) 
    {
        if (pattern[j] == text[i]) 
        {
            j++;
            i++;
        }

        if (j == len_pattern) 
        {
            printf("Строка: %2d| Столбец: %2d| Индекс начала подстроки: %d\n", line_number, i - j + 1, i - j);
            j = prefix[j-1];
        }
         
        else if (i < len_text && pattern[j] != text[i]) 
        {
            if (j != 0)
                j = prefix[j-1];
            else
                i++;
        }
    }
}

void print_prefix_function(const char *pattern)
{
    int *mas = prefix_function(pattern);
    printf("Префикс функция: ");
    for (int i = 0; i < strlen(pattern); i++)
        printf("%d ", mas[i]);
    printf("\n\n");
    free(mas);
}
   
int print_text(const char *input_text)
{
    FILE *text = fopen(input_text, "r");
    if (!text)
    {
        printf("Файл не открылся\n");
        return -1;
    }
    //printf("%s:\n", input_text);
    char str[MaxLength];
    while (!feof(text))
    {
        fgets(str, MaxLength + 1, text);
        printf("%s", str);
    }
    printf("\n");
    return 0;
}

int KMP_search_in_file(const char *input_text, const char *pattern)
{
    FILE *text = fopen(input_text, "r");

    if (!text)
    {
        printf("Файл не открылся\n");
        return -1;
    }
    printf("\nПуть: %s\n", input_text);
    int line_number = 1;     
    char str[MaxLength];
    while (fgets(str, MaxLength + 1, text) != NULL)
    {
        KMP(str, pattern, line_number);
        line_number++;
    }
    
    return 0;
}

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int print_dirent(const char *input_dir)
{
    DIR* dir = opendir(input_dir);
    struct dirent *ent;

    if (!dir)
    {
        printf("Директория не открылась\n");
        return -1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        char path[1000];
        snprintf(path, sizeof(path), "%s/%s", input_dir, ent->d_name);
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
        {
            if (ent->d_type == DT_DIR)
            {
                print_dirent(path);
            }else{
                printf("%s/%s\n", input_dir, ent->d_name);
        }
        }
    }
    closedir(dir);
    return 0;
}

int KMP_search_in_dirent(const char *input_dir, const char *pattern)
{
    DIR* dir = opendir(input_dir);
    struct dirent *ent;

    if (!dir)
    {
        printf("Директория не открылась\n");
        return -1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            char path[1000];
            snprintf(path, sizeof(path), "%s/%s", input_dir, ent->d_name);
            if (ent->d_type == DT_DIR)
            {
                KMP_search_in_dirent(path, pattern);
            }else{
                KMP_search_in_file(path, pattern);
            }
        }
    }
    closedir(dir);
    return 0;
}
int KMP_search_in_dirent_without_recursion(const char *input_dir, const char *pattern)
{
    DIR* dir = opendir(input_dir);
    struct dirent *ent;

    if (!dir)
    {
        printf("Директория не открылась\n");
        return -1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            char path[1000];
            snprintf(path, sizeof(path), "%s/%s", input_dir, ent->d_name);
                KMP_search_in_file(path, pattern);
            
        }
    }
}

int KMP_search_in_child_dirent(const char *input_dir, const char *pattern)
{
    DIR* dir = opendir(input_dir);
    struct dirent *ent;

    if (!dir)
    {
        printf("Директория не открылась\n");
        return -1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            char path[1000];
            snprintf(path, sizeof(path), "%s/%s", input_dir, ent->d_name);
            if (ent->d_type == DT_DIR)
            {
                KMP_search_in_dirent(path, pattern);
                KMP_search_in_file(path, pattern);
            }
                
            
        }
    }
}