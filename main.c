#include <stdio.h>
#include "printf.h"

int	main(void)
{
	int a = 731;
	int N = -7938;
	char b = 'g';
	char *s = "hello world";
	char *p = &b;
	int result;
	int result2;

	result = ft_printf("FT_PRI: %% %d %i %u %x %X %c %s %p\n", a, a, a, a, a, b, s, p);
	result2 = printf("PRINTF: %% %d %i %.u %x %X %c %s %p\n", a, a, a, a, a, b, s, p);
	printf("ft_printf: %d  printf: %d\n\n", result, result2);

	result = ft_printf("FT_PRI: %% %.5d %6.4i %15.12u %15.10x %15.10X %5c %20.2s %20p\n", N, N, N, N, N, b, s, p);
	result2 = printf("PRINTF: %% %.5d %6.4i %15.12u %15.10x %15.10X %5c %20.2s %20p\n", N, N, N, N, N, b, s, p);
	printf("ft_printf: %d  printf: %d\n\n", result, result2);

	result = ft_printf("FT_PRI: %% %010d %*.*i %u %x %X %-13c %-20.100s %-20p\n", a, 15, 10, a, a, a, a, b, s, p);
	result2 = printf("PRINTF: %% %010d %*.*i %u %x %X %-13c %-20.100s %-20p\n", a, 15, 10, a, a, a, a, b, s, p);
	printf("ft_printf: %d  printf: %d\n\n", result, result2);

	result = ft_printf("FT_PRI: %% %d %i %u %x %X %c %*.*s %p\n", a, a, a, a, a, b, 15, 10, s, p);
	result2 = printf("PRINTF: %% %d %i %u %x %X %c %*.*s %p\n", a, a, a, a, a, b, 15, 10, s, p);
	printf("ft_printf: %d  printf: %d\n\n", result, result2);
	return (0);
}

