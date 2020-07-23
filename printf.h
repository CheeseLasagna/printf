/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:46:15 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/23 18:40:32 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

struct	s_flags{
	int wd;
	int pr;
	int ps;
	int sz;
	int strchk;
};

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_itoahex(long unsigned int n, int bigsmall);
char	*ft_itoaun(unsigned int n);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

int		ft_position(const char *s);
int		ft_precision(const char *s, va_list argptr, int *szptr, int *strchk);
int		ft_width(const char *s, va_list argptr);
int		ft_spacezero(const char *s);

void	dec(struct s_flags fs, va_list argptr, int *count);
void	uns(struct s_flags fs, va_list argptr, int *count);
void	hexs(struct s_flags fs, va_list argptr, int *count);
void	hexb(struct s_flags fs, va_list argptr, int *count);
void	dec_ext(struct s_flags fs, int *count, char *strarg);
void	uns_hex_ext(struct s_flags fs, int *count, char *strarg);
void	print_dec_uns_hex(struct s_flags fs, char fill, char *strarg);
int		dec_prec(int precision, char *strarg, int len);

void	print_char(struct s_flags fs, va_list argptr, int *count);
void	print_str(struct s_flags fs, va_list argptr, int *count);
void	print_str2(struct s_flags fs, char *str, char fill);
int		str_null(struct s_flags fs, int *count);
void	print_space(int wd, char fill);
void	print_adr(struct s_flags fs, va_list argptr, int *count);
int		adr_null(struct s_flags fs, int *count);

int		ft_printf(const char *s, ...);
#endif
