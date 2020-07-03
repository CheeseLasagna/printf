#include "printf.h"

int	ft_width(const char *s, va_list argptr)
{
	int width;

	width = 0;
	while (*s == '-' || *s == '*' || (*s >= '0' && *s <= '9'))
	{
		if (*s == '*')
		{
			width = va_arg(argptr, int);
			return (width);
		}
		if (*s >= '1' && *s <= '9')
		{
			width = ft_atoi(s);
			return (width);
		}
		s++;
	}
	return (width);
}
			
