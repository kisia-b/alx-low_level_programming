#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_97 - checks for the correct number of arguments
 * @arg: number of arguments
 *
 * Return: void
 */
void check_97(int arg)
{
	if (arg != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_98 - checks that file_from exists and can be read
 * @chck: checks if true of false
 * @file: file_from name
 * @fdfrom: file descriptor of file_from, or -1
 * @fdto: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check_98(ssize_t chck, char *file, int fdfrom, int fdto)
{
	if (chck == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fdfrom != -1)
			close(fdfrom);
		if (fdto != -1)
			close(fdto);
		exit(98);
	}
}

/**
 * check_99 - checks that file_to was created and/or can be written to
 * @chck: checks if true of false
 * @file: file_to name
 * @fdfrom: file descriptor of file_from, or -1
 * @fdto: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check_99(ssize_t chck, char *file, int fdfrom, int fdto)
{
	if (chck == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fdfrom != -1)
			close(fdfrom);
		if (fdto != -1)
			close(fdto);
		exit(99);
	}
}

/**
 * check_100 - checks that file descriptors were closed properly
 * @chck: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check_100(int chck, int fd)
{
	if (chck == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - opies the content of a file to another file.
 * @arg: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int arg, char *argv[])
{
	int fdfrom, fdto, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	check_97(arg);
	fdfrom = open(argv[1], O_RDONLY);
	check_98((ssize_t)fdfrom, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fdto = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_99((ssize_t)fdto, argv[2], fdfrom, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fdfrom, buffer, 1024);
		check_98(lenr, argv[1], fdfrom, fdto);
		lenw = write(fdto, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		check_99(lenw, argv[2], fdfrom, fdto);
	}
	close_to = close(fdto);
	close_from = close(fdfrom);
	check_100(close_to, fdto);
	check_100(close_from, fdfrom);
	return (0);
}
