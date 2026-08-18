#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/**
 * close_fd - closes a file descriptor and handles errors
 * @fd: file descriptor to close
 *
 * Return: nothing
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the content of one file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close_fd(file_from);
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	bytes_read = read(file_from, buffer, 1024);
	while (bytes_read > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close_fd(file_from);
			close_fd(file_to);
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			exit(99);
		}

		bytes_read = read(file_from, buffer, 1024);
	}

	if (bytes_read == -1)
	{
		close_fd(file_from);
		close_fd(file_to);
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	close_fd(file_from);
	close_fd(file_to);

	return (0);
}
