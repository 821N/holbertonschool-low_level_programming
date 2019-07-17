#include <stdlib.h>

/**
 * worddup - duplicate a string until the next space or \0
 *
 * @str: start
 * Return: pointer to new string, or NULL
 */
char *worddup(char *str)
{
	char *temp, *ret;
	int length;

	/* check str */
	if (!str)
		return (NULL);
	for (temp = str; *temp && *temp != ' '; temp++)
		length++;
	/* allocate */
	ret = temp = malloc(length);
	if (!ret)
		return (NULL);
	/* copy */
	while (*str && *str != ' ')
		*temp++ = *str++;
	*temp = '\0';

	return (ret);
}

/**
 * strtow - split a string into words
 *
 * @str: string
 * Return: list of words
 */
char **strtow(char *str)
{
	int words = 0, inword = 0;
	char *temp = str, **ret;

	for (; *temp; temp++)
		if (inword)
		{
			if (*temp == ' ')
				inword = 0;
		}
		else if (*temp != ' ')
		{
			inword = 1;
			words++;
		}

	ret = malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	for (words = 0, temp = str; *temp; temp++)
		if (inword)
		{
			if (*temp == ' ')
				inword = 0;
		}
		else if (*temp != ' ')
		{
			inword = 1;
			ret[words] = worddup(temp);
			if (!ret[words++])
			{
				/* free everything */
				while (words > 0)
					free(ret[--words]);
				free(ret);
				return (NULL);
			}
		}
	ret[words] = NULL;
	return (ret);
}