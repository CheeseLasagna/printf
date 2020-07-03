#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argptr;
	char x;
	char *str;
	int chislo;

	va_start(argptr, s);
	while(*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
			{
				x = va_arg(argptr, int);
				write(1, &x, 1);
			}
			else if(*s == 's')
			{
				str = va_arg(argptr, char *);
				write(1, str, 5);
			}
			if (*s == 'X')
			{
				chislo = va_arg(argptr, int);
				puthex(chislo, 1);
			}
		}
		else
			write (1, s, 1);
		s++;
	}
	va_end(argptr);
	return (0);
}
int	main(void)
{
	ft_printf("first %c\nsecond %c\nthird %X\nforth %s\n", 'a', 'b', -5, "cykanax");
	return (0);
}
		
