/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:46:30 by sdzamari          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:38 by sdzamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*

This function receives the char found after the percentage sign (%) in the ft_printf function
and calls the corresponding function to convert it to the right type and print it.

*/
static void	convert_type(const char c, t_hold *arguments)
{
	if (c == 'c')
		ft_char(arguments);
	else if (c == 's')
		ft_string(arguments);
	else if (c == 'd' || c == 'i')
		ft_integer(arguments);
	else if (c == 'u')
		ft_unsignedint(arguments);
	else if (c == 'x' || c == 'X')
		ft_hex(arguments, c);
	else if (c == 'p')
		ft_pointer(arguments);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		arguments->count++;
	}
}

/*

The t_hold struct is initialized by allocation space in memory.
The counter in the struct is initialized by being set to 0.

*/
static t_hold	*init_args(void)
{
	t_hold	*arguments;

	arguments = (t_hold *)malloc(sizeof(t_hold));
	if (!arguments)
		return (NULL);
	arguments->count = 0;
	return (arguments);
}

/* 

The ellipsis notation in the ft_printf prototype implies that it accepts an unspecified 
number of arguments. The *str, in this case, is the last required argument.

The variable *arguments of type t_hold, is a pointer to a struct defined in the header file.
The struct consists of a va_list (type from the stdarg library) and a counter (as ft_printf return the total number of characters in the printed string).

The t_hold struct arguments is initialized with init_args() and the va_list must be
started and ended using the stdarg library macros va_start & va_end. 

The function returns and int that represents each character printed in the final string.
The counter must be updated for each character printed of any type.

*/
int	ft_printf(const char *str, ...)
{
	t_hold	*arguments;
	int		count;
	int		i;

	i = 0;
	count = 0;
	arguments = init_args();
	va_start(arguments->arg, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			arguments->count++;
		}
		else if (str[i] == '%')
			convert_type(str[++i], arguments);
		i++;
	}
	count = arguments->count;
	va_end(arguments->arg);
	free(arguments);
	return (count);
}
