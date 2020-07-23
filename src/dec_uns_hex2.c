/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_uns_hex2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:50:57 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/23 18:43:42 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	dec_ext(struct s_flags fs, int *count, char *strarg)
{
	int		len;
	char	fill;

	fill = ' ';
	if (fs.pr || fs.ps)
		fs.sz = 0;
	if (fs.sz)
		fill = '0';
	len = ft_strlen(strarg);
	fs.pr = dec_prec(fs.pr, strarg, len);
	if (fs.wd < 0)
	{
		fill = ' ';
		fs.ps = 1;
		fs.wd = fs.wd * -1;
	}
	if (fs.wd > len + fs.pr)
		fs.wd = fs.wd - len - fs.pr;
	else
		fs.wd = 0;
	print_dec_uns_hex(fs, fill, strarg);
	*count = *count + fs.wd + fs.pr + len;
}

void	uns_hex_ext(struct s_flags fs, int *count, char *strarg)
{
	int		len;
	char	fill;

	fill = ' ';
	if (fs.pr || fs.ps)
		fs.sz = 0;
	if (fs.sz)
		fill = '0';
	len = ft_strlen(strarg);
	if (fs.pr > len)
		fs.pr = fs.pr - len;
	else
		fs.pr = 0;
	if (fs.wd > len + fs.pr)
		fs.wd = fs.wd - len - fs.pr;
	else
		fs.wd = 0;
	print_dec_uns_hex(fs, fill, strarg);
	*count = *count + fs.wd + fs.pr + len;
}

int		dec_prec(int precision, char *strarg, int len)
{
	if (strarg[0] == '-')
	{
		if (precision > len - 1)
			precision = precision - len + 1;
		else
			precision = 0;
	}
	else if (precision > len)
		precision = precision - len;
	else
		precision = 0;
	return (precision);
}
