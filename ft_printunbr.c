/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:28:34 by gguardam          #+#    #+#             */
/*   Updated: 2025/05/17 13:30:16 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recursiveunbr(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n / 10)
		count += ft_recursiveunbr(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}

int	ft_printunbr(unsigned int number)
{
	long	n;
	int		count;

	n = number;
	count = 0;
	count += ft_recursiveunbr(n);
	return (count);
}
