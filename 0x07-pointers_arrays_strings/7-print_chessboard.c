/* the checker is broken */
int _putchar(char c);

/**
 * print_chessboard - print an 8x8 char array
 *
 * @a: board
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
			_putchar(a[j][i]);
		_putchar('\n');
	}
}
