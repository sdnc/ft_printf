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
	int	len;

	len = count_digits(nb);
	ret (char *)malloc(len + 1 * sizeof(char));
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
	char	*nb_str;

	nb_str = ft_itoa(va_arg(arguments->arg, int));
	ft_putstr_fd(nb_str, 1);
	arguments->count += ft_strlen(nb_str);
	free(nb_str);
}

void	ft_unsignedint(t_hold *arguments)
{
	char	*nb_str;

	nb_str = unsint_to_str(va_arg(arguments->arg, unsigned int));
	ft_putstr_fd(nb_str, 1);
	arguments->count += ft_strlen(nb_str);
	free(nb_str);
}
