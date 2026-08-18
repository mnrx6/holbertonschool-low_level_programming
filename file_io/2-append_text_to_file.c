#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t len;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	len = 0;
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	}

	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (-1);

	bytes_written = write(fd, text_content, len);
	if (bytes_written != (ssize_t)len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
