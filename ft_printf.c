/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:55:59 by gguardam          #+#    #+#             */
/*   Updated: 2025/05/14 14:07:58 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/////////////////////////////////////////////////
void ft_recursivenbr(int n)
{
    if (n / 10)
		ft_recursivenbr(n / 10);
    
    char digit = (n % 10) + '0';
    write(1, &digit, 1);
}

void ft_printnbr(va_list vargs)
{
	int	number = va_arg(vargs, int);
	if(number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	if(number >= 10)
	{
		ft_recursivenbr(number);
	}
	else
	{
		number = number + '0';
		write(1, &number, 1);
	}
}
/////////////////////////////////////////////////
void ft_printchar(va_list vargs)
{
    char charsy = (char)va_arg(vargs, int);
    write(1, &charsy, 1);
}
/////////////////////////////////////////////////
void ft_printstr(va_list vargs)
{
	int	i;
	char *stringy;

	i = 0;
	stringy = (char *)va_arg(vargs, char *);
	while(*stringy != '\0')
	{
		write(1, stringy, 1);
		*stringy++;
	}
}
/////////////////////////////////////////////////
void ft_printpstr(va_list vargs)
{
	void *stringy = (void *)va_arg(vargs, void *);
	write(1, &stringy, 1);
}

static void	parameter_manager(char	stringy, va_list vargs)
{
	if (stringy == 'c')
		ft_printchar(vargs);
	else if (stringy == 's')
		ft_printstr(vargs);
	else if (stringy == 'p')
		ft_printpstr(vargs);
	else if (stringy == 'd' || stringy == 'i')
		ft_printnbr(vargs);
	// else if (stringy == 'u')
	// {
	// 	va_arg(vargs, int);
	// 	printf("%i", vargs);
	// }
	// else if (stringy == 'x' || stringy == 'X')
	// {
	// 	va_arg(vargs, int);
	// 	printf("%i", vargs);
	// }
	// else if (stringy == '%')
	// {
	// 	va_arg(vargs, int);
	// 	printf("%i", vargs);
	// }
}

int ft_printf(char const *stringy, ...)
{
    va_list vargs;

    va_start(vargs, stringy);
    while (*stringy != '\0')
    {
        if (*stringy == '%')
        {   
            stringy++;
            parameter_manager(*stringy, vargs);
        }
        else
        {
            write(1, stringy, 1);
        }
        stringy++;
    }
    va_end(vargs);
    return 0;
}

int	main()
{
	int	i = 4;
	int	*j = &i;
	ft_printf("%c\n%i\n%d\n%s\n%p\n", 'A', 456789, -2, "Esto es un string", j);
	return 0;
}
