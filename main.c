#include <stdio.h>
#include <stdarg.h>
#include "include/ft_printf.h"
//#include "src/ft_printf.c"

int main(void)
{
	int fourtytwo = 42;
	int *ptr = &fourtytwo;
	//ft_printf("%p\n", ptr);
	while (*ptr)
	{
		write(1, ptr, sizeof(int));
		ptr++;
	}
	return (0);
}
