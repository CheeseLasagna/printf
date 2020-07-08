/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:27:23 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/07 14:51:59 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char *adjust_flags(struct flags fs, va_list argptr, const char *s, int strchk)
{
	while (*s != 'c' && *s != 's' && *s != 'p' && *s != 'd' && *s != 'i' &&	*s != 'u' && *s != 'x' && *s != 'X') 
		s++;
	if (*s == 'd' || *s == 'i')
		dec(fs, argptr);	
	else if (*s == 'u')
		uns(fs, argptr);	
	else if (*s == 'x')
		hexS(fs, argptr);	
	else if (*s == 'X')
		hexB(fs, argptr);	
	else if (*s == 'c')
		print_char(fs, argptr);
	else if (*s == 's')
		print_str(fs, argptr, strchk);
	else if (*s == 'p')
		print_adr(fs, argptr);	
	return (s);
}

const char	*get_flags(const char *s, va_list argptr)
{
	struct flags fs;
	int strchk;

	strchk = 0;
	fs.sz = ft_spacezero(s);
	fs.ps = ft_position(s);
	fs.wd = ft_width(s, argptr);
	fs.pr = ft_precision(s, argptr, &fs.sz, &strchk);
	s = adjust_flags(fs, argptr, s, strchk);
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
