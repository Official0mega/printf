#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @lt: List of arguments to be printed.
 * @roll: List of arguments.
 *
 * Return: width
 */

int get_width(const char *format, int *lt, va_list roll)
{
	int record;
	int width = 0;

	for (record = *lt + 1; format[record] != '\0'; record++)
	{
		if (is_digit(format[record]))
		{
			width *= 10;
			width += format[record] - '0';
		}
		else if (format[record] == '*')
		{
			record++;
			width = va_arg(roll, int);
			break;
		}
		else
			break;
	}
	*lt = record - 1;
	return (width);
}
