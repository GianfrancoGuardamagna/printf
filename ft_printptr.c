/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:47:27 by gguardam          #+#    #+#             */
/*   Updated: 2025/05/17 13:50:04 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex_ptr(uintptr_t num, char *hex)
{
	char	c;
	int		count;

	count = 0;
	if (num >= 16)
		count += ft_printhex_ptr(num / 16, hex);
	c = hex[num % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_printptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_printhex_ptr((uintptr_t)ptr, "0123456789abcdef");
	return (count);
}
