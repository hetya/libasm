#include "libasm.h"

void	print_result_test(char *str, int result)
{
	if (result)
		printf("%s: \033[0;31mfailed!\033[0m\n", str);
	else
		printf("%s: \033[0;32mpassed!\033[0m\n", str);
}

int	main(void)
{
	print_result_test("ft_write", test_ft_write());
	print_result_test("ft_read", test_ft_read());
	print_result_test("ft_strcmp", test_ft_strcmp());
	print_result_test("ft_strcpy", test_ft_strcpy());
	print_result_test("ft_strdup", test_ft_strdup());
	print_result_test("ft_strlen", test_ft_strlen());
}
