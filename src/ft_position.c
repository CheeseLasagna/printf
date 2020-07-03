int	ft_position(const char *s)
{
	int position;

	position = 0;
	while (*s == '0' || *s == '-')
	{
		if (*s == '-')
		{
			position = 1;
			return (position);
		}
		s++;
	}
	return (position);
}
