#include "libasm.h"

static int	test_basic_copy(void)
{
	char	libasm_dest[100];
	char	expected_dest[100];
	char	*src;

	src = "Hello, World!";
	ft_strcpy(libasm_dest, src);
	strcpy(expected_dest, src);
	if (strcmp(libasm_dest, expected_dest) != 0)
	{
		printf("Test 1 failed: expected %s, got %s\n",
			expected_dest, libasm_dest);
		return (1);
	}
	return (0);
}

static int	test_empty_string(void)
{
	char	libasm_dest[100];
	char	expected_dest[100];
	char	*src;

	src = "";
	ft_strcpy(libasm_dest, src);
	strcpy(expected_dest, src);
	if (strcmp(libasm_dest, expected_dest) != 0)
	{
		printf("Test 2 failed: expected %s, got %s\n",
			expected_dest, libasm_dest);
		return (1);
	}
	return (0);
}

int	test_ft_strcpy(void)
{
	if (test_basic_copy())
		return (1);
	if (test_empty_string())
		return (1);
	return (0);
}
