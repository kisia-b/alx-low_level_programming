#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @fname: Pointer to the file name.
 * @letters: Number of letters the
 *           function should read and print.
 *
 * Return: When the function fails or fname is NULL - 0.
 *         Op/wr - the number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *fname, size_t letters)
{
	ssize_t op, rd, wr;
	char *buf;

	if (fname == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	op = open(fname, O_RDONLY);
	rd = read(op, buf, letters);
	wr = write(STDOUT_FILENO, buf, rd);

	if (op == -1 || rd == -1 || wr == -1 || wr != rd)
	{
		free(buf);
		return (0);
	}
