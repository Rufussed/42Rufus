#include <stdio.h>
#include <stdarg.h>

void	simple_printf(const char *fmt, ...)
{
	va_list	args;
	va_start(args, fmt);

	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int	i = va_arg(args, int);
			printf("%d\n", i);
		} else if (*fmt == 'c') {
			int	c = va_arg(args, int);
			printf("%c\n", (char)c);
		} else if (*fmt == 'f') {
			double	d = va_arg(args, double);
			printf("%f\n", d);
		} else if (*fmt == 's') {
			char	*s = va_arg(args, char*);
			printf("%s\n", s);
		}
		++fmt;
	}

	va_end(args);
}

int	main(void)
{
	//simple_printf("dcffs", 3, 'a', 1.999, 42.5, "Hello, World!");
	printf("test bad pointer %p", (void *)(-1));
	printf("test bad pointer %u", -1);
	return (0);
}
