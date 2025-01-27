#include "libasm.h"
#include <stdio.h>
#include <string.h>

int	test_ft_strcmp(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = "Hello";
	str2 = "World";
	str3 = "";
	str4 = "Hello, World!";
	str5 = "Hello";
	if (ft_strcmp(str1, str1) != strcmp(str1, str1))
		return (1);
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
		return (1);
	if (ft_strcmp(str1, str3) != strcmp(str1, str3))
		return (1);
	if (ft_strcmp(str1, str4) != strcmp(str1, str4))
		return (1);
	if (ft_strcmp(str1, str5) != strcmp(str1, str5))
		return (1);
	return (0);
}
