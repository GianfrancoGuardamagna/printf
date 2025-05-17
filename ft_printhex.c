/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:23:24 by gguardam          #+#    #+#             */
/*   Updated: 2025/05/17 13:25:23 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int numby, char *hex)
{
	char	c;
	int		count;

	count = 0;
	if (numby >= 16)
		count += ft_printhex(numby / 16, hex);
	c = hex[numby % 16];
	count += write(1, &c, 1);
	return (count);
}
