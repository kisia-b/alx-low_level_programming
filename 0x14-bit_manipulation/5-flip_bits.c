
#include "main.h"

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dif, res;
	unsigned int y, x;

	y = 0;
	res = 1;
	dif = n ^ m;
	for (x = 0; x < (sizeof(unsigned long int) * 8); x++)
	{
		if (res == (dif & res))
			y++;
		res <<= 1;
	}

	return (y);
}
