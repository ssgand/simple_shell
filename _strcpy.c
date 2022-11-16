#include "shell.h"

/**
 * _strcpy - function to copy a string
 * @dest: the destination of the copy
 * @src: the source of the string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - function to duplicate a string
 * @str: the string to duplicate
 *
 * Return: a character
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *c;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	for (len++; len--;)
		c[len] = *--str;
	return (c);
}
/**
 * _puts - function to print an input string
 * @str: the strint to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - function the print the argument to stdout
 * @c: the character to print
 *
 * Return: an integer
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
