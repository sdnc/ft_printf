#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_hold
{
	va_list	arg;
	int		count;
}				t_hold;

#endif
