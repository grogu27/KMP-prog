#include "funk.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("argc < 3 or argc > 3\n");
        return -1;
    }
    
    const char *pattern = argv[1];
    const char *input_file = argv[2];
    
    // if (pattern(str) == 0 || strlen(pattern) == 0)
    // {
    //     printf("Длина строки или длина подстроки равны нулю\n");
    //     return 0;
    // }
    printf("\nПодстрока: %s\n", argv[1]);
    print_prefix_function(pattern);
    print_text(input_file);

    double start = wtime();
    KMP_search_in_file(input_file, pattern);
    double time = wtime() - start;
    printf("\nВремя выполнения алгоритма: %lf\n", time);

    return 0;
}







// 012345
// AABAAB  AABAAB  AABAAB    AABAAB  
// AABAAB   AABAAB   AABAAB     AABAAB
// 
// prefix[strlen()] = {0,1,0,1,2,3}