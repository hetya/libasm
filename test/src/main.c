#include "libasm.h"

int main()
{
    char *test_str = "Hello World!\n";
    // write
    printf("ret : %ld, should return : %ld\n", ft_write(1, test_str, strlen(test_str)), write(1, test_str, strlen(test_str)));
    // printf("ret : %ld, should return : %ld\n", ft_write(-1, test_str, strlen(test_str)), write(-1, test_str, strlen(test_str)));
    // strlen();
    printf("ft_strlen: %ld, strlen: %ld\n", ft_strlen(test_str), strlen(test_str));
    // test strcpy
    char *test_strcpy = "Hello World!";
    char strcpy_dest[100] = {0};
    char ft_strcpy_dest[100] = {0};
    printf("ft_strcpy: %s, strcpy: %s\n", ft_strcpy(ft_strcpy_dest, test_strcpy), strcpy(strcpy_dest, test_strcpy));
    printf("new string :%s, %s\n", strcpy_dest, ft_strcpy_dest);
    // test strcmp
    char *test_strcmp1 = "Hello World!";
    char *test_strcmp2 = "Hello World!";
    char *test_strcmp3 = "Hello World";
    printf("ft_strcmp: %d, strcmp: %d\n", ft_strcmp(test_strcmp1, test_strcmp2), strcmp(test_strcmp1, test_strcmp2));
    printf("ft_strcmp: %d, strcmp: %d\n", ft_strcmp(test_strcmp1, test_strcmp3), strcmp(test_strcmp1, test_strcmp3));
    printf("ft_strcmp: %d, strcmp: %d\n", ft_strcmp(test_strcmp3, test_strcmp1), strcmp(test_strcmp3, test_strcmp1));
    // test strdup
    char *test_strdup = "Hello World!";
    char *result_ft_strdup;
    char *result_strdup;
    result_ft_strdup = ft_strdup(test_strdup);
    result_strdup = strdup(test_strdup);
    printf("ft_strdup: %s, strdup: %s\n", result_ft_strdup, result_strdup);
    free(result_ft_strdup);
    free(result_strdup);
}