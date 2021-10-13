#include "ft_printf.h"
/* Try why va_arg with char instead of int? */

void	ft_char(t_hold *arguments)
{
	ft_putchar_fd(va_arg(arguments, int), 1);
	arguments->count++;
}

void	ft_string(t_hold *arguments)
{
	int	len;
	char	*str;

	str = va_arg(arguments->arg, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		arguments->count += 6;
	{
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		arguments->count += len;
	}
}
