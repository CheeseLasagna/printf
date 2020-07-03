#include "printf.h"
#include <stdio.h>

void	print_char(int wd, int ps, va_list argptr)
{
	char c;
	int fill;
	
	fill = 0;
	c = va_arg(argptr, int);
	if (!ps)
		print_space(wd, fill);
	write (1, &c, 1);
	if (ps)
		print_space(wd, fill);
}

void	print_str(int wd, int pr, int ps, va_list argptr, int strchk)
{
	char *c;
	int fill;
	int len;

	fill = 0;
	c = va_arg(argptr, char *);
	len = ft_strlen(c);
	if (pr > len || (pr == 0 && !strchk))
		pr = len;
	if (!ps)
		print_space(wd, fill);
	while (pr--)
	{
		write(1, &(*c), 1);
		c++;
	}
	if (ps)
		print_space(wd, fill);
}
