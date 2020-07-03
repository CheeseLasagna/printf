#include <unistd.h>
#include "printf.h"

void puthex(unsigned int n, int fd)
{

    if (n < 16)
	{
        if (n > 9)
            ft_putchar_fd(n + 55, fd);
        else
		    ft_putchar_fd(n + 48, fd);
	}
	else
	{
		puthex(n / 16, fd);
		puthex(n % 16, fd);
	}
}
