#include "main.h"

/**
 * _printf - custom printf function
 * @format: the format string
 * @...: variable number of arguments
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = handle_format(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * handle_format - handles the format string and arguments
 * @format: the format string
 * @args: the va_list of arguments
 * Return: the number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int i, printed_chars = 0;
	char c;
	char *str;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_args(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				str = va_args(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					write(1, str, 1);
					str++;
					printed_chars++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
	}
	return (printed_chars);
}
