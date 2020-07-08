#include "printf.h"

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
void	print_space(int wd, char fill)
{
	while (wd)
	{
		write(1, &fill, 1);
		wd--;
	}
}

void	print_char(struct flags fs, va_list argptr)
{
	char c;
	char fill;
	
	fill = ' ';
	if (fs.wd)
		fs.wd = fs.wd - 1;	
	c = va_arg(argptr, int);
	if (!fs.ps)
		print_space(fs.wd, fill);
	write (1, &c, 1);
	if (fs.ps)
		print_space(fs.wd, fill);
}

void	print_str(struct flags fs, va_list argptr, int strchk)
{
	char *c;
	char fill;
	int len;

	fill = ' ';
	c = va_arg(argptr, char *);
	len = ft_strlen(c);
	if (fs.pr > len || (fs.pr == 0 && !strchk))
		fs.pr = len;
	if (fs.wd > fs.pr || fs.wd > len)
	{
		if (fs.pr < len)
			fs.wd = fs.wd - fs.pr;
		else
			fs.wd = fs.wd - len;
	}
	else
		fs.wd = 0;
	if (!fs.ps)
		print_space(fs.wd, fill);
	while (fs.pr--)
		write(1, &(*c++), 1);
	if (fs.ps)
		print_space(fs.wd, fill);
}

void print_adr(struct flags fs, va_list argptr)
{
	long unsigned int arg;
	char *strarg;
	int len;
	char fill;

	fill = ' ';
	arg = va_arg(argptr, long unsigned int);
	strarg = ft_itoahex(arg, 0);
	len = ft_strlen(strarg);
	if (fs.wd > len + 2)
		fs.wd = fs.wd - len - 2;
	else
		fs.wd = 0;
	if(!fs.ps)
		print_space(fs.wd, fill);
	write(1, "0x", 2);
	write(1, strarg, ft_strlen(strarg));
	if (fs.ps)
		print_space(fs.wd, fill);
	free(strarg);	
}
