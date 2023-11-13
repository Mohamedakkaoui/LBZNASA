/**
 * _printf - function that produces output according to a format
 * @format: a character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list print;
	int x, y;
	char *b;

	va_start(print, format);
	if (format == NULL)
		return (-1);
	for (x = 0; *format; x++)
	{
		if (*format != '%')
			_putchar(*format);
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			else if (*format == 'c')
				_putchar(va_arg(print, int));
			else if (*format == 'd')
				_putchar(va_arg(print, int));
			else if (*format == 'i')
				_putchar(va_arg(print, int));
			else if (*format == 's')
			{
				y = 0;
				b = va_arg(print, char *);
				while (*b != '\0')
				{
					_putchar(*b++);
					y++;
				}
				x += (y - 1);
			}
			else if (*format == '%')
			{
				_putchar('%');
			}
			else
			{
				va_end(print);
				return (-1);
			}
		}
		format++;
	}
	va_end(print);
	return (x);
}

