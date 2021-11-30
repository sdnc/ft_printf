/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:53:34 by sdzamari          #+#    #+#             */
/*   Updated: 2021/10/14 12:30:51 by sdzamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

The functions called by convert_type() must first retrieve the argument using the stdarg 
library MACRO va_arg with the va_list and the type to retrieve.

The counter must be updated.

The arguments is then to be converted and printed.

The functions must be free of memory leaks.

*/
static int	count_digits(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*unsint_to_str(unsigned int nb)
{
	char	*ret;
	int		len;

	len = count_digits(nb);
	ret = (char *)malloc(len + 1 * sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

void	ft_integer(t_hold *arguments)
{
	char	*nbr_str;

	nbr_str = ft_itoa(va_arg(arguments->arg, int));
	ft_putstr_fd(nbr_str, 1);
	arguments->count += ft_strlen(nbr_str);
	free(nbr_str);
}

void	ft_unsignedint(t_hold *arguments)
{
	char	*str;

	str = unsint_to_str(va_arg(arguments->arg, unsigned int));
	ft_putstr_fd(str, 1);
	arguments->count += ft_strlen(str);
	free(str);
}
