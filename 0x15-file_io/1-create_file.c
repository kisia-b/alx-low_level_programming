#include "main.h"
/**
 * create_file -creates an array of chars, and initializes
 *
 * @content: is a NULL terminated string to write to the file
 * @fname: is the name of the file to create
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *fname, char *content)
{
	int op, wr, lenght = 0;

	if (fname == NULL)
		return (-1);

	if (content != NULL)
	{
		for (lenght = 0; content[lenght];)
			lenght++;
	}

	op = open(fname, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(op, content, lenght);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
