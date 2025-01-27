#include "libasm.h"

static int	test_ft_strlen2(void)
{
	char	*str3;
	char	*str4;
	char	*str5;

	str3 = "This is a longer string.";
	str4 = "Another\0string";
	str5 = "1234567890";
	if (ft_strlen(str3) != strlen(str3))
	{
		printf("Test 3 failed: expected %lu, got %lu\n",
			strlen(str3), ft_strlen(str3));
		return (1);
	}
	if (ft_strlen(str4) != strlen(str4))
	{
		printf("Test 4 failed: expected %lu, got %lu\n",
			strlen(str4), ft_strlen(str4));
		return (1);
	}
	if (ft_strlen(str5) != strlen(str5))
	{
		return (printf("Test 5 failed: expected %lu, got %lu\n",
				strlen(str5), ft_strlen(str5)) || 1);
	}
	return (0);
}

int	test_ft_strlen(void)
{
	char	*str1;
	char	*str2;

	str1 = "";
	str2 = "Hello";
	if (ft_strlen(str1) != strlen(str1))
	{
		printf("Test 1 failed: expected %lu, got %lu\n",
			strlen(str1), ft_strlen(str1));
		return (1);
	}
	if (ft_strlen(str2) != strlen(str2))
	{
		printf("Test 2 failed: expected %lu, got %lu\n",
			strlen(str2), ft_strlen(str2));
		return (1);
	}
	if (test_ft_strlen2())
		return (1);
	return (0);
}
