#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d", hex_to_int(av[1]));
	else
		printf("error");
}
