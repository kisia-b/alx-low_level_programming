#include "main.h"
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int y = 1;
	unsigned int x;

	for (x = 1; x <= pow; x++)
		y *= base;
	return (y);
}
void print_binary(unsigned long int n)
{
	unsigned long int a, b;
	char dot;

	dot = 0;
	a = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (a != 0)
	{
		b = n & a;
		if (b == a)
		{
			dot = 1;
			_putchar('1');

		}
		else if (dot == 1 || a == 1)
		{
			_putchar('0');
		}
		a >>= 1;
	}
}
