/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:46:15 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/03 12:59:21 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_itoahex(unsigned int n, int bigsmall);
char	*ft_itoaun(unsigned int n);
int		ft_atoi(const char *nptr);
int		ft_position(const char *s);
int		ft_precision(const char *s, va_list argptr, int *szptr, int *strchk);
int		ft_width(const char *s, va_list argptr);
int		ft_spacezero(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

void	dec(int wd, int pr, int ps, int sz, va_list argptr);
void	uns(int wd, int pr, int ps, int sz, va_list argptr);
void	hexS(int wd, int pr, int ps, int sz, va_list argptr);
void	hexB(int wd, int pr, int ps, int sz, va_list argptr);

void	print_char(int wd, int ps, va_list argptr);
void	print_str(int wd, int pr, int ps, va_list argptr, int strchk);
void	print_space(int wd, char fill);
#endif
