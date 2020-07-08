#include "printf.h"

int	ft_position(const char *s)
{
	int position;

	position = 0;
	while (*s == '0' || *s == '-')
	{
		if (*s == '-')
		{
			position = 1;
			return (position);
		}
		s++;
	}
	return (position);
}

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

int	ft_spacezero(const char *s)
{
	int spacezero;

	spacezero = 0;
	if (*s == '0')
		spacezero = 1;
	return (spacezero);
}

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
