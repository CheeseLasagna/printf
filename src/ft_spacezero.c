int	ft_spacezero(const char *s)
{
	int spacezero;

	spacezero = 0;
	if (*s == '0')
		spacezero = 1;
	return (spacezero);
}
