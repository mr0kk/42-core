#include <stdio.h>

void	test(int x)
{
	if (x > 3)
		return ;
	printf("here\n");
}

int	main(void)
{
	test(4);
}
