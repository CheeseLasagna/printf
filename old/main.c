#include <stdio.h>

/*struct flags{
	int s;
	int y;
};*/
int	main(void)
{
	int a = 42; 
	int *ptr;
//	char *str = "Random";*/
/*	struct flags beb;
	beb.s = 20;
	beb.y = 40;*/
	ptr = &a;	
//	printf("decimal %i\nunsigned %u\nhexasmall %x\nhexabig %X\nchar %25c\nstring %.s\npppp %25p\nlast %%\n", a, a, a, a, a, str, ptr);
	printf("decimal %d\naddress %015p\n", a, ptr);
	return (0);
}
