#include "main.h"

/**
 * _stringlength - finds length of a string
 * @string: pointer to the string
 *
 * Return: length of the string
 */
size_t _stringlength(char *string)
{
	size_t x;

	for (x = 0; string[x]; x++)
		;
	return (x);
}

/**
 * append_text_to_file - appends a text at the end of a file.
 * @fname: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *fname, char *text_content)
{
	int f;
	ssize_t length;

	if (fname == NULL)
		return (-1);
	f = open(fname, O_WRONLY | O_APPEND);
	if (f == -1)
		return (-1);
	if (text_content != NULL)
		length = write(f, text_content, _stringlength(text_content));
	close(f);
	if (length == -1)
		return (-1);
	return (1);
}
