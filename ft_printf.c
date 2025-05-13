#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	parameter_count(const char	*stringy)
{
	int	i;
	int	parameters;

	i = 0;
	parameters = 0;
	while(stringy[i] != '\0')
	{
		if (stringy[i - 1] == '%' && (stringy[i] == 'c' || stringy[i] == 's' || stringy[i] == 'p' || stringy[i] == 'd' || stringy[i] == 'i' || stringy[i] == 'u' || stringy[i] == 'x' || stringy[i] == 'X' || stringy[i] == '%'))
			parameters++;
		i++;
	}
	return parameters;
}

int	ft_printf(char const *stringy, ...)
{
	va_list	vargs;
	char	*variable;
	int	parameters;

	va_start(vargs, stringy);
	parameters = parameter_count(stringy);
	while (parameters > 0)
	{
		variable = va_arg(vargs, char *);
		puts(variable);
		parameters--;
	}
	va_end(vargs);
	return 0;
}

int	main()
{
	ft_printf("Ay Miguel: %s\n", 5);
	return 0;
}
