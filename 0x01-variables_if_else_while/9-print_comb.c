#include <stdio.h>

/**
 *main--
 *Return:0
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i)
		{
			putchar(',');
			putchar(' ');
		}
		putchar('0' + i);
	}
	putchar('\n');

	return (0);
}
