#include "main.h"
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int y = 0;
		if (!b)
		return (0);
	for (x = 0; b[x] != '\0'; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
	}
	for (x = 0; b[x] != '\0'; x++)
	{
		j <<= 1;
		if (b[x] == '1')
			j += 1;
	}
	return (y);
}
