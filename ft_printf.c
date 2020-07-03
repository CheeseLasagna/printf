/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:27:23 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/03 13:01:15 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

const char *adjust_flags(int wd, int pr, int ps, int sz, va_list argptr, const char *s, int strchk)
{
	while (*s != 'c' && *s != 's' && *s != 'p' && *s != 'd' && *s != 'i' &&	*s != 'u' && *s != 'x' && *s != 'X') 
		s++;
	if (*s == 'd' || *s == 'i')
		dec(wd, pr, ps, sz, argptr);	
	else if (*s == 'u')
		uns(wd, pr, ps, sz, argptr);	
	else if (*s == 'x')
		hexS(wd, pr, ps, sz, argptr);	
	else if (*s == 'X')
		hexB(wd, pr, ps, sz, argptr);	
	else if (*s == 'c')
		print_char(wd, ps, argptr);
	else if (*s == 's')
		print_str(wd, pr, ps, argptr, strchk);
/*	else if (*s == 'p')
		smth*/
	return (s);
}

const char	*get_flags(const char *s, va_list argptr)
{
	int width;
	int precision;
	int position;
	int spacezero;
	int strchk;

	strchk = 0;
	spacezero = ft_spacezero(s);
	position = ft_position(s);
	width = ft_width(s, argptr);
	precision = ft_precision(s, argptr, &spacezero, &strchk);
//	printf("spacezero %d\nprecision %d\nposition %d\nwidth %d\n", spacezero, precision, position, width);
	s = adjust_flags(width, precision, position, spacezero, argptr, s, strchk);
	return (s);
}	
	
int	ft_printf(const char *s, ...)
{
	va_list argptr;

	va_start(argptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				write (1, "%", 1);
			else
				s = get_flags(s, argptr);
		}
		else
			write(1, s, 1);
		s++;
	}
	va_end(argptr);
	return (0);
}

int main(void)
{
	char *s = "hello world";
	char c = 'z';	

	ft_printf("string %.s\ncharacter %c\n", s, c);
	return (0);
}
