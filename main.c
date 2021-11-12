#include "includes/ft_printf.h"

int main(int ac, char **av)
{
    int i = 1;

    while (i < ac)
    {
        ft_printf(av[i]);
        ft_putstr_fd("\n", 1); 
        i++;
    }
    return (0);
}