#include <stdio.h>
#include "printf.h"

int	main(void)
{
	//char *s = NULL;
	//int a = 55;
	//int *p = &a;

	ft_printf("|%.*u|\n", -3, 12345);
	printf("|%.*u|\n", -3, 12345);
	//printf("string |%s|\ndecimal |%d|\nunsigned |%u|\nhexa |%x|\ncharacter |%c|\n", s, NULL, NULL, NULL, NULL);
//	printf("string |%s|\naddress |%-10p|\n", s, NULL);
	return (0);
}
