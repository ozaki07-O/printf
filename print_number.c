#include "main.h"
/**
* _isdigit - checks for digit
*
* @c: character to compare
*
* Return: 1 if true, 0 if false
*
*/
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/**
 * _strlen - returns lenght of a string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i;

	while (*s++)
		i++;
	return (i);
}
/**
* print_number - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
*
*Return: chars printed
*/
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}
/**
* print_number_right_shift - prints a number with options
*@str: the base number as a string
* @params: the parameter struct
*
*Return: chars printed
*/
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		n += putchar(' ');
	n += _puts(str);
	return (n);
}
/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
*/
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag & !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += putchar(' '), i++;
	n += puts(str);
	while (i++ < params->width)
		n += putchar(pad_char);
	return (n);
}
