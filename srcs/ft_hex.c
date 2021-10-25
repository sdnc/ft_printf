/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:04:28 by sdzamari          #+#    #+#             */
/*   Updated: 2021/10/25 13:04:35 by sdzamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_addresslength(unsigned long nb, int *i)
{
	char	*ptr;

	while (nb >= 16)
	{
		nb /= 16;
		*i++;
	}
	ptr = (char *)malloc((*i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[*i] = '\0';
	return (ptr);
}

void	ft_hex(t_hold *pointers, char c)
{
	unsigned int	n;
	int				i;
	char			*str;

	n = va_arg(pointers->arg, unsigned int);
	i = 1;
	str = ft_addresslength(n, &i);
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else if (c == 'x')
			str[i] = 'a' - 10 + (n % 16);
		else
			str[i] = 'A' - 10 + (n % 16);
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ft_pointer(t_hold *pointers)
{
	unsigned long	n;
	int				i;
	char			*str;

	n = va_arg(pointers->arg, unsigned long);
	i = 1;
	str = ft_addresslength(n, &i);
	ft_putstr_fd("0x", 1);
	pointers->count += 2;
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else
			str[i] = 'a' - 10 + (n % 16);
		n /= 16;
		i--;
		pointers->count++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
