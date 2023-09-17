#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
  * print_unsigned - function that prints unsigned numbers
  * @types:- list of args
  * @buffer:- buffer array for print
  * @flags:- checks active flags
  * @width:- width
  * @precision:- precesion details
  * @size:- size
  * Return:- Always 0 (success)
  */

int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
  * print_octal - function that prints numbers in octal notation
  * @types:- list of args
  * @flags:- chacks active flags
  * @buffer:- buffer array for print
  * @width:- width
  * @precision:- precision specification
  * @size:- size
  * Return:- Always 0 (success)
  */

int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
  * print_hexadecimal - function that prints unsigned numbers in hexadecimal
  * @types:- list of args
  * @buffer:- buffer array
  * @flags:- chacks for active flags
  * @width:- width
  * @precision:- precision specification
  * @size:- size
  * Return:- Always 0 (success)
  */

int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
				width, precision, size));
}

/**
  * print_hexa_upper - function that prints hexadecimals in upper
  * @types:- list of args
  * @buffer:- buffer array
  * @flags:- checks active flags
  * @width:- width
  * @precision:- precision specification
  * @size:- size
  * Return:- Always 0 (success)
  */

int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width,
				precision, size));
}

/**
  * print_hexa - function that prints hexadeciamal in lower/upper
  * @types:- list of args
  * @map_to:- arrays of values to map numbers to
  * @buffer:- buffer array
  * @flags:- chacks for active flags
  * @flag_ch:- checks active flags
  * @width:- width
  * @precision:- precision specification
  * @size:- size
  * Return:- Always 0 (success)
  */

int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
