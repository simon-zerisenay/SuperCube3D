#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;
	int	i = -1;

	va_list	arg;
	va_start(arg, format);

	while (format[++i])
	{
		if ((format[i] == '%') && ((format[i + 1] == 's') || (format[i + 1] == 'd') || (format[i + 1] == 'x')))
		{
			i++;
			if (format[i] == 's')
				put_string(va_arg(arg, char *), &length);
			else if (format[i] == 'd')
				put_digit((long long int)va_arg(arg, int), 10, &length);
			else if (format[i] == 'x')
				put_digit((long long int)va_arg(arg, unsigned int), 16, &length);
		}
		else
			length += write(1, format + i, 1);
	}
	return (va_end(arg), length);
}