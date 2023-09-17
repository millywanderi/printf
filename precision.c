#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
  * get_precision - finds the precision for printing
  * @format:- formatted string in which to print the args
  * @i:- args to print
  * @ap:- list of args ap == list
  * Return:- Always 0 (success)
  */

int get_precision(const char *format, int *i, va_list ap)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (precision);
}
