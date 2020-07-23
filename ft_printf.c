/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:27:23 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/23 18:54:47 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*adjust_flags(struct s_flags fs, va_list argptr, const char *s,
																int *count)
{
	while (*s != 'c' && *s != 's' && *s != 'p' && *s != 'd' && *s != 'i' &&
										*s != 'u' && *s != 'x' && *s != 'X')
		s++;
	if (*s == 'd' || *s == 'i')
		dec(fs, argptr, count);
	else if (*s == 'u')
		uns(fs, argptr, count);
	else if (*s == 'x')
		hexs(fs, argptr, count);
	else if (*s == 'X')
		hexb(fs, argptr, count);
	else if (*s == 'c')
		print_char(fs, argptr, count);
	else if (*s == 's')
		print_str(fs, argptr, count);
	else if (*s == 'p')
		print_adr(fs, argptr, count);
	return (s);
}

const char	*get_flags(const char *s, va_list argptr, int *count)
{
	struct s_flags fs;

	fs.strchk = 0;
	fs.sz = ft_spacezero(s);
	fs.ps = ft_position(s);
	fs.wd = ft_width(s, argptr);
	fs.pr = ft_precision(s, argptr, &fs.sz, &fs.strchk);
	s = adjust_flags(fs, argptr, s, count);
	return (s);
}

const char	*rezat(const char *s, va_list argptr, int *count)
{
	if (*s == '%')
	{
		write(1, "%", 1);
		*count = *count + 1;
	}
	else
		s = get_flags(s, argptr, count);
	return (s);
}

int			ft_printf(const char *s, ...)
{
	va_list	argptr;
	int		count;

	count = 0;
	va_start(argptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			s = rezat(s, argptr, &count);
		}
		else
		{
			write(1, s, 1);
			count++;
		}
		s++;
	}
	va_end(argptr);
	return (count);
}
