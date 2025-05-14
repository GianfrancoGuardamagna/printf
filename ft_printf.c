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

// void ft_printnbr(va_list vargs)
// {
// 	int	number = va_arg(vargs, int);
// 	write(1, &number, sizeof(int));
// }

void ft_printchar(va_list vargs)
{
	char charsy = va_arg(vargs, char);
	write(1, &charsy, sizeof(char));
}

// void ft_printstr(va_list vargs)
// {
	
// }

static void	parameter_manager(char	stringy, va_list vargs)
{
	if (stringy == 'c')
	{
		ft_printchar(vargs);
	}
	// else if (stringy == 's')
	// {
	// 	va_arg(vargs, char *);
	// 	printf("%s", vargs);
	// }
	// else if (stringy == 'p')
	// {
	// 	va_arg(vargs, void *);
	// 	printf("%p", vargs);
	// }
	// else if (stringy == 'd' || stringy == 'i')
	// {
	// 	va_arg(vargs, int);
	// 	printf("%i", vargs);
	// }
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

int	ft_printf(char const *stringy, ...)
{
	va_list	vargs;

	va_start(vargs, stringy);
	while (*stringy != '\0')
	{
		if (*stringy == '%')
		{	
			stringy++;
			parameter_manager(*stringy, vargs);
		}
		stringy++;
		write(1, stringy, sizeof(char));
	}
	va_end(vargs);
	return 0;
}

int	main()
{
	ft_printf("%c Ay Miguel %c\n", 'A', 'r');
	return 0;
}
