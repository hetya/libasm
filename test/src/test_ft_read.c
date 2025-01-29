#include "libasm.h"

static int	test_read_empty_file(void)
{
	int		fd;
	char	expected_output[100];
	char	obtained_output[100];
	ssize_t	expected_ret;
	ssize_t	obtained_ret_value;

	fd = open("./test/test_read_empty_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 100);
	if (lseek(fd, 0, SEEK_SET))
	{
		perror("lseek");
		return (1);
	}
	obtained_ret_value = ft_read(fd, obtained_output, 100);
	close(fd);
	if (expected_ret != obtained_ret_value
		|| strcmp(expected_output, obtained_output) != 0)
	{
		printf("Test 3 failed: expected %ld and buf %s, got %ld and buf %s\n",
			expected_ret, expected_output, obtained_ret_value, obtained_output);
		return (1);
	}
	return (0);
}

static int	test_read_zero_bytes(void)
{
	int		fd;
	char	expected_output[100];
	char	obtained_output[100];
	ssize_t	expected_ret;
	ssize_t	obtained_ret_value;

	fd = open("./test/test_read_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 0);
	if (lseek(fd, 0, SEEK_SET))
	{
		perror("lseek");
		return (1);
	}
	obtained_ret_value = ft_read(fd, obtained_output, 0);
	close(fd);
	if (expected_ret != obtained_ret_value)
	{
		printf("Test 4 failed: expected %ld and buf %s, got %ld and buf %s\n", 
		expected_ret, expected_output, obtained_ret_value, obtained_output);
		return (1);
	}
	return (0);
}

static int	test_buffer_larger_than_file(void)
{
	int		fd;
	char	expected_output[1000];
	char	obtained_output[1000];
	ssize_t	expected_ret;
	ssize_t	obtained_ret_value;

	fd = open("./test/test_read_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 1000);
	expected_output[expected_ret] = 0;
	if (lseek(fd, 0, SEEK_SET))
	{
		perror("lseek");
		return (1);
	}
	obtained_ret_value = ft_read(fd, obtained_output, 1000);
	obtained_output[obtained_ret_value] = 0;
	close(fd);
	if (expected_ret != obtained_ret_value
		|| strcmp(expected_output, obtained_output) != 0)
	{
		printf("Test 5 failed: expected %ld and buf %s, got %ld and buf %s\n",
			expected_ret, expected_output, obtained_ret_value, obtained_output);
		return (1);
	}
	return (0);
}

static int	test_invalid_fd(void)
{
	char	expected_output[100];
	char	obtained_output[100];
	ssize_t	expected_ret;
	ssize_t	obtained_ret_value;
	int		expected_errno;

	expected_ret = read(-1, expected_output, 100);
	expected_errno = errno;
	obtained_ret_value = ft_read(-1, obtained_output, 100);
	if (expected_ret != obtained_ret_value || expected_errno != errno)
	{
		printf("Test 2 failed: exp %ld and errno %d, got %ld and errno %d\n",
			expected_ret, expected_errno, obtained_ret_value, errno);
		return (1);
	}
	if (test_read_empty_file() != 0)
		return (2);
	if (test_read_zero_bytes() != 0)
		return (4);
	if (test_buffer_larger_than_file() != 0)
		return (5);
	return (0);
}

int	test_ft_read(void)
{
	int		fd;
	char	expected_output[100];
	char	obtained_output[100];
	ssize_t	expected_ret;
	ssize_t	obtained_ret_value;

	fd = open("./test/test_read_file", O_RDONLY);
	expected_ret = read(fd, expected_output, 100);
	expected_output[expected_ret - 1] = 0;
	if (lseek(fd, 0, SEEK_SET))
	{
		perror("lseek");
		return (1);
	}
	obtained_ret_value = ft_read(fd, obtained_output, 100);
	obtained_output[obtained_ret_value - 1] = 0;
	close(fd);
	if (expected_ret != obtained_ret_value
		|| strcmp(expected_output, obtained_output) != 0)
		return (printf("Test 1 failed: epx %ld and buf %s, got %ld and %s\n",
				expected_ret, expected_output, obtained_ret_value,
				obtained_output) || 1);
	if (test_invalid_fd() != 0)
		return (3);
	return (0);
}
