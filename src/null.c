/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:32:10 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/27 13:18:41 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	str_null(struct s_flags fs, int *count)
{
	int		len;
	char	*str;

	len = 6;
	str = "(null)";
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
	print_str2(fs, str, ' ');
	return (*count);
}
