#include "libasm.h"

int	test_ft_strdup(void)
{
	char	*str1;
	char	*str2;
	char	*obtained_dup1;
	char	*obtained_dup2;

	str2 = "";
	str1 = "Hello, World!";
	obtained_dup1 = ft_strdup(str1);
	if (strcmp(obtained_dup1, str1) != 0)
	{
		printf("Test 1 failed: expected %s, got %s\n", str1, obtained_dup1);
		return (1);
	}
	obtained_dup2 = ft_strdup(str2);
	if (strcmp(obtained_dup2, str2) != 0)
	{
		printf("Test 2 failed: expected %s, got %s\n", str2, obtained_dup2);
		return (1);
	}
	free(obtained_dup1);
	free(obtained_dup2);
	return (0);
}
