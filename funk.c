#include "funk.h"

int *prefix_function(char *str) 
{
    int *pref = malloc(sizeof(int) * strlen(str));
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

void KMP(char *text, char *pattern)
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
            printf("Найдено вхождение на позиции: %d\n", i - j);
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
