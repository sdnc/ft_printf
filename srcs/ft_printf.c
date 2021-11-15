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

static void	ft_getflag(const char c, t_hold *arguments)
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

static t_hold	*init_args(void)
{
	t_hold	*arguments;

	arguments = (t_hold *)malloc(sizeof(t_hold));
	if (!arguments)
		return (NULL);
	arguments->count = 0;
	return (arguments);
}

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
			ft_getflag(str[++i], arguments);
		i++;
	}
	count = arguments->count;
	va_end(arguments->arg);
	free(arguments);
	return (count);
}
