/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:57:35 by sdzamari          #+#    #+#             */
/*   Updated: 2021/10/14 12:24:17 by sdzamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_hold
{
	va_list	arg;
	int		count;
}				t_hold;

void	ft_char(t_hold *arguments);
void	ft_string(t_hold *arguments);
void	ft_hex(t_hold *pointers, char c);
void	ft_pointer(t_hold *pointers);
void	ft_integer(t_hold *arguments);
void	ft_unsignedint(t_hold *arguments);
int		ft_printf(const char *str, ...);

#endif
