#include "printf.h"

void	print_space(int wd, char fill)
{
	while (wd)
	{
		write(1, &fill, 1);
		wd--;
	}
}

void	print_dec(int wd, int pr, int ps, char fill, char *strarg)
{
	if (!ps)
	{
		if (fill == '0' && strarg[0] == '-' && wd)
		{
			write(1, &strarg[0], 1);
			strarg++;
		}
		print_space(wd, fill);
	}
	write(1, strarg, ft_strlen(strarg));
	if (pr)
	{
		while (pr--)
			write (1, "0", 1);
	}
	if (ps)
		print_space(wd, fill);
}
		

void	dec(int wd, int pr, int ps, int sz, va_list argptr)
{
	int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, int);
	strarg = ft_itoa(arg);
	if (pr || ps)
		sz = 0;
	if (sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (wd > len)
		wd = wd - len;
	else
		wd = 0;
	if (pr > len)
		pr = pr - len;
	else
		pr = 0;
	print_dec(wd, pr, ps, fill, strarg);
	free (strarg);
}	 
	
void	uns(int wd, int pr, int ps, int sz, va_list argptr)
{
	unsigned int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, unsigned int);
	strarg = ft_itoaun(arg);
	if (pr || ps)
		sz = 0;
	if (sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (wd > len)
		wd = wd - len;
	else
		wd = 0;
	if (pr > len)
		pr = pr - len;
	else
		pr = 0;
	print_dec(wd, pr, ps, fill, strarg);
	free (strarg);
}	 
	
void	hexB(int wd, int pr, int ps, int sz, va_list argptr)
{
	unsigned int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, unsigned int);
	strarg = ft_itoahex(arg, 1);
	if (pr || ps)
		sz = 0;
	if (sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (wd > len)
		wd = wd - len;
	else
		wd = 0;
	if (pr > len)
		pr = pr - len;
	else
		pr = 0;
	print_dec(wd, pr, ps, fill, strarg);
	free (strarg);
}	 
	void	hexS(int wd, int pr, int ps, int sz, va_list argptr)
{
	unsigned int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, unsigned int);
	strarg = ft_itoahex(arg, 0);
	if (pr || ps)
		sz = 0;
	if (sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (wd > len)
		wd = wd - len;
	else
		wd = 0;
	if (pr > len)
		pr = pr - len;
	else
		pr = 0;
	print_dec(wd, pr, ps, fill, strarg);
	free (strarg);
}	 
