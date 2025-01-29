#include "libasm.h"

static int	test_writing_file(void)
{
	int		fd;
	ssize_t	obtained_return;
	ssize_t	expected_return;

	fd = open(".test_write_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	obtained_return = ft_write(fd, "Hello, File!\n", 13);
	expected_return = ft_write(fd, "Hello, File!\n", 13);
	if (obtained_return != expected_return)
	{
		printf("Test 2 failed: expected %ld, got %ld\n",
			expected_return, obtained_return);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	test_invalid_fd(void)
{
	ssize_t	obtained_return;
	ssize_t	expected_return;
	int		expected_errno;
	int		obtained_errno;

	expected_return = write(-1, "Hello, Error!\n", 14);
	expected_errno = errno;
	obtained_return = ft_write(-1, "Hello, Error!\n", 14);
	obtained_errno = errno;
	if (obtained_return != expected_return || expected_errno != obtained_errno)
	{
		printf("Test 3 Failed: exp %ld and errno %d, got %ld and errno %d\n",
			expected_return, expected_errno, obtained_return, obtained_errno);
		return (1);
	}
	return (0);
}

static int	test_write_null(void)
{
	ssize_t	obtained_return;
	ssize_t	expected_return;
	int		expected_errno;
	int		obtained_errno;

	expected_return = write(1, NULL, 0);
	expected_errno = errno;
	obtained_return = ft_write(1, NULL, 0);
	obtained_errno = errno;
	if (expected_return != obtained_return || expected_errno != obtained_errno)
	{
		printf("Test 4 failed: exp %ld and errno %d, got %ld and errno %d\n",
			expected_return, expected_errno, obtained_return, obtained_errno);
		return (1);
	}
	return (0);
}

static int	test_write_0_bytes(void)
{
	ssize_t	obtained_return;
	ssize_t	expected_return;

	expected_return = write(1, "Hello, Zero!\n", 0);
	obtained_return = ft_write(1, "Hello, Zero!\n", 0);
	if (expected_return != obtained_return)
	{
		printf("Test 5 failed: expected %ld, got %ld\n", expected_return,
			obtained_return);
		return (1);
	}
	return (0);
}

int	test_ft_write(void)
{
	ssize_t	expected_return;
	ssize_t	obtained_return;

	printf("====== TEST OUTPUT ======\n");
	expected_return = write(1, "Hello, World!\n", 14);
	obtained_return = ft_write(1, "Hello, World!\n", 14);
	printf("=========================\n");

	if (expected_return != obtained_return)
	{
		printf("Test 1 failed: expected %ld, got %ld\n", expected_return,
			obtained_return);
		return (1);
	}
	if (test_writing_file())
		return (1);
	if (test_invalid_fd())
		return (1);
	if (test_write_null())
		return (1);
	if (test_write_0_bytes())
		return (1);
	return (0);
}
