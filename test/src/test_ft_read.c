#include "libasm.h"

static int	test_read_empty_file(void)
{
	int		fd;
	char	expected_output[100];
	char	libasm_output[100];
	ssize_t	expected_ret;
	ssize_t	libasm_ret;

	fd = open("./test/empty_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 100);
	libasm_ret = ft_read(fd, libasm_output, 100);
	close(fd);
	if (expected_ret != libasm_ret
		|| strcmp(expected_output, libasm_output) != 0)
		return (1);
	return (0);
}

static int	test_invalid_fd(void)
{
	char	expected_output[100];
	char	libasm_output[100];
	ssize_t	expected_ret;
	ssize_t	libasm_ret;
	int		expected_errno;

	expected_ret = read(-1, expected_output, 100);
	expected_errno = errno;
	libasm_ret = ft_read(-1, libasm_output, 100);
	if (expected_ret != libasm_ret || expected_errno != errno)
		return (1);
	return (0);
}

static int	test_read_zero_bytes(void)
{
	int		fd;
	char	expected_output[100];
	char	libasm_output[100];
	ssize_t	expected_ret;
	ssize_t	libasm_ret;

	fd = open("./test/test_read_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 0);
	libasm_ret = ft_read(fd, libasm_output, 0);
	close(fd);
	if (expected_ret != libasm_ret)
		return (1);
	return (0);
}

static int	test_buffer_larger_than_file(void)
{
	int		fd;
	char	expected_output[1000];
	char	libasm_output[1000];
	ssize_t	expected_ret;
	ssize_t	libasm_ret;

	fd = open("./test/test_read_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 1000);
	libasm_ret = ft_read(fd, libasm_output, 1000);
	close(fd);
	if (expected_ret != libasm_ret
		|| strcmp(expected_output, libasm_output) != 0)
		return (1);
	return (0);
}

int	test_ft_read(void)
{
	int		fd;
	char	expected_output[100];
	char	libasm_output[100];
	ssize_t	expected_ret;
	ssize_t	libasm_ret;

	fd = open("./test/test_read_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 100);
	libasm_ret = ft_read(fd, libasm_output, 100);
	close(fd);
	printf("libasm_ret: %ld, expected_ret: %ld\n", libasm_ret, expected_ret);
	printf("libasm_output: %s, expected_output: %s\n", libasm_output,
		expected_output);
	if (expected_ret != libasm_ret
		|| strcmp(expected_output, libasm_output) != 0)
		return (1);
	if (test_read_empty_file() != 0)
		return (2);
	if (test_invalid_fd() != 0)
		return (3);
	if (test_read_zero_bytes() != 0)
		return (4);
	if (test_buffer_larger_than_file() != 0)
		return (5);
	return (0);
}
