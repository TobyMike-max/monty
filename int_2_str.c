#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_num_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * int_conv_str - Gets a character pointer to new string containing int
 * @num: Number to convert to string
 *
 * Return: Character pointer to newly created string. NULL if malloc fails.
 */
char *int_conv_str(int num)
{
	unsigned int temp;
	int len = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	len = get_num_len(temp, 10);

	if (num < 0 || num_l < 0)
		len++;
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, len);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Gets the absolute value of an integer
 * @i: Integer to get absolute value of
 *
 * Return: Unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_num_len - Gets length of buffer needed for an unsigned int
 * @num: Number to get length needed for
 * @base: Base of number representation used by buffer
 *
 * Return: Integer containing length of buffer needed (NULL excluded)
 */
int get_num_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Fills buffer with correct numbers up to base 36
 * @num: Number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem = '0';
		num /= base;
		i--;
	}
}
