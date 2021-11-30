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

/*

The functions called by convert_type() must first retrieve the argument using the stdarg 
library MACRO va_arg with the va_list and the type to retrieve.

The counter must be updated.

The arguments is then to be converted and printed.

The functions must be free of memory leaks.

*/
static char	*malloc_addresslength(unsigned long nb, int *i)
{
	char	*ptr;

	while (nb >= 16)
	{
		nb /= 16;
		*i += 1;
	}
	ptr = (char *)malloc((*i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[*i] = '\0';
	return (ptr);
}


void	ft_hex(t_hold *pointers, char c)
{
	unsigned int	address_nbr;
	int				i;
	char			*str;

	address_nbr = va_arg(pointers->arg, unsigned long);
	i = 1;
	str = malloc_addresslength(address_nbr, &i);
	i--;
	while (i >= 0)
	{
		if (address_nbr % 16 < 10)
			str[i] = '0' + (address_nbr % 16);
		else if (c == 'x')
			str[i] = 'a' - 10 + (address_nbr % 16);
		else
			str[i] = 'A' - 10 + (address_nbr % 16);
		address_nbr /= 16;
		i--;
		pointers->count++;
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
