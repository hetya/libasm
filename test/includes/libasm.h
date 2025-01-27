#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>

// Libasm functions
ssize_t	ft_read(int fd, void *buf, size_t count);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
ssize_t	ft_write(int fd, const void *buf, size_t count);

// Test functions
int		test_ft_read(void);
int		test_ft_strcmp(void);
int		test_ft_strcpy(void);
int		test_ft_strdup(void);
int		test_ft_strlen(void);
int		test_ft_write(void);

#endif