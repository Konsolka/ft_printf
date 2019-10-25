#include <stdio.h>
#include <stdlib.h>
int		main(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 8);
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = ' ';
	str[6] = 'W';
	str[7] = 'o';
	str++;
	str++;
	printf("%c", str[-1]);
	return (0);
}