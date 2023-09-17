#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
  * get_width - calculates the width for printing
  * @format:- string in which to print args
  * @i:- list of args to print
  * @ap:- list of args
  * Return:- Always 0 (success)
  */

int get_width(const char *format, int *i, va_list ap)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (width);
}
