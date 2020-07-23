/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:40:44 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/23 18:42:28 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_space(int wd, char fill)
{
	while (wd)
	{
		write(1, &fill, 1);
		wd--;
	}
}

void	print_char(struct s_flags fs, va_list argptr, int *count)
{
	char c;
	char fill;

	fill = ' ';
	if (fs.wd)
		fs.wd = fs.wd - 1;
	c = va_arg(argptr, int);
	if (!fs.ps)
		print_space(fs.wd, fill);
	write(1, &c, 1);
	if (fs.ps)
		print_space(fs.wd, fill);
	*count = *count + fs.wd + 1;
}

void	print_str2(struct s_flags fs, char *str, char fill)
{
	if (!fs.ps)
		print_space(fs.wd, fill);
	while (fs.pr--)
		write(1, &(*str++), 1);
	if (fs.ps)
		print_space(fs.wd, fill);
}

void	print_str(struct s_flags fs, va_list argptr, int *count)
{
	char	*c;
	char	fill;
	int		len;

	fill = ' ';
	c = va_arg(argptr, char *);
	len = ft_strlen(c);
	if (c == NULL)
	{
		*count = str_null(fs, count);
		return ;
	}
	if (fs.pr > len || (fs.pr == 0 && !fs.strchk) || fs.pr < 0)
		fs.pr = len;
	if (fs.wd < 0)
	{
		fs.ps = 1;
		fs.wd = fs.wd * -1;
	}
	if (fs.wd > fs.pr)
		fs.wd = fs.wd - fs.pr;
	else
		fs.wd = 0;
	*count = *count + fs.wd + fs.pr;
	print_str2(fs, c, fill);
}

void	print_adr(struct s_flags fs, va_list argptr, int *count)
{
	long unsigned int	arg;
	char				*strarg;
	int					len;

	arg = va_arg(argptr, long unsigned int);
	strarg = ft_itoahex(arg, 0);
	if (*strarg == '0')
	{
		*count = adr_null(fs, count);
		free(strarg);
		return ;
	}
	len = ft_strlen(strarg);
	if (fs.wd > len + 2)
		fs.wd = fs.wd - len - 2;
	else
		fs.wd = 0;
	if (!fs.ps)
		print_space(fs.wd, ' ');
	write(1, "0x", 2);
	write(1, strarg, ft_strlen(strarg));
	if (fs.ps)
		print_space(fs.wd, ' ');
	free(strarg);
	*count = *count + fs.wd + 2 + len;
}
