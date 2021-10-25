/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:55:27 by sdzamari          #+#    #+#             */
/*   Updated: 2021/10/14 11:59:51 by sdzamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_hold *arguments)
{
	ft_putchar_fd(va_arg(arguments->arg, int), 1);
	arguments->count++;
}

void	ft_string(t_hold *arguments)
{
	int		len;
	char	*str;

	str = va_arg(arguments->arg, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		arguments->count += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		arguments->count += len;
	}
}
