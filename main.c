#include "funk.h"

int main()
{
    char str[] = "abcdqqqabcd";
    char pattern[] = "abcd"; 
    // int *mas = prefix_function(pattern);
    // for (int i = 0; i < strlen(pattern); i++)
    //     printf("%d ", mas[i]);
    // printf("\n");
    printf("\nСтрока: %s\n", str);
    KMP(str, pattern);
    return 0;
}







// 012345
// AABAAB  AABAAB  AABAAB    AABAAB  
// AABAAB   AABAAB   AABAAB     AABAAB
// 
// prefix[strlen()] = {0,1,0,1,2,3}