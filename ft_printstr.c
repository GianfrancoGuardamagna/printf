/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:30:47 by gguardam          #+#    #+#             */
/*   Updated: 2025/05/17 13:40:30 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *stringy)
{
	int	len;

	if (!stringy)
		return (write(1, "(null)", 6));
	len = ft_strlen(stringy);
	write(1, stringy, len);
	return (len);
}
