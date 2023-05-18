#include "funk.h"

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        const char *pattern = argv[1];
        const char *input_dir = argv[2];
        printf("\nНачальная директория: %s\n", argv[2]);
        printf("\nПодстрока: %s\n", argv[1]);
        print_prefix_function(pattern);
        print_dirent(input_dir);
        double start = wtime();
        KMP_search_in_dirent_without_recursion(input_dir, pattern);
        double time = wtime() - start;
        printf("\nВремя выполнения алгоритма: %lf\n", time);
    }
    else if (argc == 4)
    {
        const char *key = argv[1];
        const char *pattern = argv[2];
        const char *input_dir = argv[3];
        if (strcmp(key, "-r") == 0)
        {
            printf("\nНачальная директория: %s\n", argv[3]);
            printf("\nПодстрока: %s\n", argv[2]);
            print_prefix_function(pattern);
            print_dirent(input_dir);
            double start = wtime();
            KMP_search_in_child_dirent(input_dir, pattern);
            double time = wtime() - start;
            printf("\nВремя выполнения алгоритма: %lf\n", time);
        } 
        
        if (strcmp(key, "-all") == 0)
        {
            printf("\nНачальная директория: %s\n", argv[3]);
            printf("\nПодстрока: %s\n", argv[2]);
            print_prefix_function(pattern);
            print_dirent(input_dir);
            double start = wtime();
            KMP_search_in_dirent(input_dir, pattern);
            double time = wtime() - start;
            printf("\nВремя выполнения алгоритма: %lf\n", time);
        } 
    }
    else{
        printf("argc < 3 or argc > 3\n");
        return -1;
    
    }
    return 0;
}





// 012345
// AABAAB  AABAAB  AABAAB    AABAAB  
// AABAAB   AABAAB   AABAAB     AABAAB
// 
// prefix[strlen()] = {0,1,0,1,2,3}