#include "funk.h"

int main(int argc, char *argv[])
{
    char str[] = "abcdqqqabcd";
    char pattern[] = ""; 

    if (strlen(str) == 0 || strlen(pattern) == 0)
    {
        printf("Длина строки или длина подстроки равны нулю\n");
        return 0;
    }
    printf("\nСтрока: %s\n", str);
    printf("\n\nПодстрока: %s\n", pattern);
    print_prefix_function(pattern);
    KMP(str, pattern);
    return 0;
}







// 012345
// AABAAB  AABAAB  AABAAB    AABAAB  
// AABAAB   AABAAB   AABAAB     AABAAB
// 
// prefix[strlen()] = {0,1,0,1,2,3}