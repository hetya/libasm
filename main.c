#include <stdio.h>
#include <unistd.h>
#include <string.h>
// #include <error.h>
// #include <stdlib.h>

ssize_t ft_read(int fd, void *buf, size_t count);
int strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);
int ft_strlen(char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);


int main(){
    // ft_strlen();
    char *test_str = "Hello World!\n";
    printf("ret : %ld, should return : %ld\n",ft_write(1, test_str, strlen(test_str)), write(1, test_str, strlen(test_str)));
    printf("ret : %ld, should return : %ld\n",ft_write(-1, test_str, strlen(test_str)), write(-1, test_str, strlen(test_str)));
}