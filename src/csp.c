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

void	print_char(struct flags fs, va_list argptr, int *count)
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
	*count = *count + fs.wd + 1;
}

void	print_str2(struct flags fs, char *str, char fill)
{
	if (!fs.ps)
		print_space(fs.wd, fill);
	while (fs.pr--)
		write(1, &(*str++), 1);
	if (fs.ps)
		print_space(fs.wd, fill);
}

void	print_str(struct flags fs, va_list argptr, int *count)
{
	char *c;
	char fill;
	int len;

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

void print_adr(struct flags fs, va_list argptr, int *count)
{
	long unsigned int arg;
	char *strarg;
	int len;
	char fill;

	fill = ' ';
	arg = va_arg(argptr, long unsigned int);
	strarg = ft_itoahex(arg, 0);
	if (*strarg == '0')
	{
		*count = adr_null(fs, count);
		free (strarg);
		return ;
	}
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
	*count = *count + fs.wd + 2 + len;
}
