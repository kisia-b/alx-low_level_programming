#include "main.h"
int get_endianness(void)
{
int x;
char *a;
x = 1;
a = (char *)&x;
return (*a);
}
