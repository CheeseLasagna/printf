#include "printf.h"

void	combine_fduxX(struct flags fs, char fill, char *strarg)
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
		write (1, "-", 1);
		strarg++;
	}	
	if (fs.pr)
	{
		while (fs.pr--)
			write (1, "0", 1);
	}
	write(1, strarg, ft_strlen(strarg));
	if (fs.ps)
		print_space(fs.wd, fill);
}
		
void	dec(struct flags fs, va_list argptr, int *count)
{
	int arg;
	char *strarg;
	char fill;
	int len;

	fill = ' ';
	arg = va_arg(argptr, int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup(""); 
	else
		strarg = ft_itoa(arg);
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
	combine_fduxX(fs, fill, strarg);
	free (strarg);
	*count = *count + fs.wd + fs.pr + len;
}	 
	
void	uns(struct flags fs, va_list argptr, int *count)
{
	unsigned int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, unsigned int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup(""); 
	else
		strarg = ft_itoaun(arg);
	if (fs.pr || fs.ps)
		fs.sz = 0;
	if (fs.sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (fs.pr > len)
		fs.pr = fs.pr - len;
	else
		fs.pr = 0;
	if (fs.wd > len + fs.pr)
		fs.wd = fs.wd - len - fs.pr;
	else
		fs.wd = 0;
	combine_fduxX(fs, fill, strarg);
	free (strarg);
	*count = *count + fs.wd + fs.pr + len;
}	 
	
void	hexB(struct flags fs, va_list argptr, int *count)
{
	unsigned int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, unsigned int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup(""); 
	else
		strarg = ft_itoahex(arg, 1);
	if (fs.pr || fs.ps)
		fs.sz = 0;
	if (fs.sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (fs.pr > len)
		fs.pr = fs.pr - len;
	else
		fs.pr = 0;
	if (fs.wd > len + fs.pr)
		fs.wd = fs.wd - len - fs.pr;
	else
		fs.wd = 0;
	combine_fduxX(fs, fill, strarg);
	free (strarg);
	*count = *count + fs.wd + fs.pr + len;
}

void	hexS(struct flags fs, va_list argptr, int *count)
{
	unsigned int arg;
	char *strarg;
	char fill;
	int len;

	arg = va_arg(argptr, unsigned int);
	if (fs.pr == 0 && arg == 0 && fs.strchk == 1)
		strarg = ft_strdup(""); 
	else
		strarg = ft_itoahex(arg, 0);
	if (fs.pr || fs.ps)
		fs.sz = 0;
	if (fs.sz)
		fill = '0';
	else
		fill = ' '; 
	len = ft_strlen(strarg);
	if (fs.pr > len)
		fs.pr = fs.pr - len;
	else
		fs.pr = 0;
	if (fs.wd > len + fs.pr)
		fs.wd = fs.wd - len - fs.pr;
	else
		fs.wd = 0;
	combine_fduxX(fs, fill, strarg);
	free (strarg);
	*count = *count + fs.wd + fs.pr + len;
}	 
