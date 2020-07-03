#include "printf.h"

int	ft_precision(const char *s, va_list argptr, int *szptr, int *strchk)
{
	int precision;

	precision = 0;
	while(*s == '-' || *s == '*' || *s == '.' || (*s >= '0' && *s <= '9'))
	{
		if (*s == '.')
		{
			*szptr = 0;
			*strchk = 1;
			s++;
			if (*s == '*')
				precision = va_arg(argptr, int);
			else
				precision = ft_atoi(s);
			return (precision);
		}
		s++;
	}
	return (precision);
}
