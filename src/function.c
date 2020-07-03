const char *function(int wd, int pr, int ps, int sz, va_list argptr, const char *s)
{
	while (*s != 'c' || *s != 's' || *s != 'p' || *s != 'd' || *s != 'i' ||	*s != 'u' || *s != 'x' || *s != 'X') 
		s++;
	if (*s == 'd' || *s == 'i')
		smth
	else if (*s == 'u')
		smth
	else if (*s == 'x')
		smth
	else if (*s == 'X')
		smth
	else if (*s == 'c')
		smth
	else if (*s == 's')
		smth
	else if (*s == 'p')
		smth
	s++;
	return (s);
}
