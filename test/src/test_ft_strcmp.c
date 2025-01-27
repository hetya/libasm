#include "libasm.h"

static int	test_ft_strcmp2(void)
{
	char	*str1;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = "Hello";
	str3 = "";
	str4 = "Hello, World!";
	str5 = "Hello";
	if (ft_strcmp(str1, str3) != strcmp(str1, str3))
	{
		printf("Test 3 failed: expected %d, got %d\n",
			strcmp(str1, str3), ft_strcmp(str1, str3));
		return (1);
	}
	if (ft_strcmp(str1, str4) != strcmp(str1, str4))
	{
		return (printf("Test 4 failed: expected %d, got %d\n",
				strcmp(str1, str4), ft_strcmp(str1, str4)) || 1);
	}
	if (ft_strcmp(str1, str5) != strcmp(str1, str5))
	{
		return (printf("Test 5 failed: expected %d, got %d\n",
				strcmp(str1, str5), ft_strcmp(str1, str5)) || 1);
	}
	return (0);
}

int	test_ft_strcmp(void)
{
	char	*str1;
	char	*str2;

	str1 = "Hello";
	str2 = "World";
	if (ft_strcmp(str1, str1) != strcmp(str1, str1))
	{
		printf("Test 1 failed: expected %d, got %d\n",
			strcmp(str1, str1), ft_strcmp(str1, str1));
		return (1);
	}
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
	{
		printf("Test 2 failed: expected %d, got %d\n",
			strcmp(str1, str2), ft_strcmp(str1, str2));
		return (1);
	}
	if (test_ft_strcmp2())
		return (1);
	return (0);
}
