#include <stdio.h>
#include <unistd.h>
#include <string.h>
// #include <error.h>
// #include <stdlib.h>

ssize_t ft_read(int fd, void *buf, size_t count);
int strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);

int main()
{
    // ft_strlen();
    char *test_str = "Hello World!\n";
    // printf("ret : %ld, should return : %ld\n",ft_write(1, test_str, strlen(test_str)), write(1, test_str, strlen(test_str)));
    // printf("ret : %ld, should return : %ld\n",ft_write(-1, test_str, strlen(test_str)), write(-1, test_str, strlen(test_str)));
    printf("ft_strlen: %ld, strlen: %ld\n", ft_strlen(test_str), strlen(test_str));
    // test strcpy
    char *test_strcpy = "Hello World!";
    char strcpy_dest[100] = {0};
    printf("ft_strcpy: %s, strcpy: %s\n", ft_strcpy(strcpy_dest, test_strcpy), strcpy(strcpy_dest, test_strcpy));
}