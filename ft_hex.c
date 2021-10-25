
#include "ft_printf.h"

void	ft_pointer(t_hold *addresses)
{
	unsigned long	n;
	int		i;
	char		*str;

	n = va_arg(addresses, unsigned long);
	i = 0;
	str = ft_strsize(n, &(i + 1));
	ft_putstr_fd("0x", 1);
	addresses->count += 2;
	while (i >= 0)
	{

	}

}
