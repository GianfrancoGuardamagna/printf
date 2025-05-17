/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:22:14 by gguardam          #+#    #+#             */
/*   Updated: 2025/05/17 13:22:59 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"

int	ft_printf(char const *stringy, ...);
int	ft_printstr(char *stringy);
int	ft_printptr(void *ptr);
int	ft_printnbr(int number);
int	ft_printchar(char charsy);
int	ft_printhex(unsigned int numby, char *hex);
int	ft_printunbr(unsigned int number);

#endif
