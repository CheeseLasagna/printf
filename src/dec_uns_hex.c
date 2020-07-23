/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_uns_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:47:05 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/23 18:43:18 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_dec_uns_hex(struct s_flags fs, char fill, char *strarg)
{
	if (!fs.ps)
	{
		if (fill == '0' && *strarg == '-' && fs.wd)
		{
			write(1, &(*strarg), 1);
			strarg++;
		}
		print_space(fs.wd, fill);
	}
	if (*strarg == '-')
	{
		write(1, "-", 1);
		strarg++;
	}
	if (fs.pr)
	{
		while (fs.pr--)
			write(1, "0", 1);
	}
	write(1, strarg, ft_strlen(strarg));
	if (fs.ps)
		print_space(fs.wd, fill);
}

void	dec(struct s_flags fs, va_list argptr, int *count)
{
	int		arg;
	char	*strarg;

	arg = va_arg(argptr, int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup("");
	else
		strarg = ft_itoa(arg);
	dec_ext(fs, count, strarg);
	free(strarg);
}

void	uns(struct s_flags fs, va_list argptr, int *count)
{
	unsigned int	arg;
	char			*strarg;

	arg = va_arg(argptr, unsigned int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup("");
	else
		strarg = ft_itoaun(arg);
	uns_hex_ext(fs, count, strarg);
	free(strarg);
}

void	hexb(struct s_flags fs, va_list argptr, int *count)
{
	unsigned int	arg;
	char			*strarg;

	arg = va_arg(argptr, unsigned int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup("");
	else
		strarg = ft_itoahex(arg, 1);
	uns_hex_ext(fs, count, strarg);
	free(strarg);
}

void	hexs(struct s_flags fs, va_list argptr, int *count)
{
	unsigned int	arg;
	char			*strarg;

	arg = va_arg(argptr, unsigned int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup("");
	else
		strarg = ft_itoahex(arg, 0);
	uns_hex_ext(fs, count, strarg);
	free(strarg);
}
