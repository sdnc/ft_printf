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
	while (--len > 0) /* --len instead of len - 1 & len-- nside loop?*/
	{
		ret[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

void	ft_integer(t_hold *arguments)
{
	char	*str;

	str = ft_itoa(va_arg(arguments->arg, int));
	ft_putstr_fd(str, 1);
	arguments->count += ft_strlen(str);
	free(str);
}

void	ft_unsignedint(t_hold *arguments)
{
	char	*str;

	str = unsint_to_str(va_arg(arguments->arg, unsigned int));
	ft_putstr_fd(str, 1);
	arguments->count += ft_strlen(str);
	free(str);
}
