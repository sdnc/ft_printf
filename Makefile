# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 12:53:33 by sdzamari          #+#    #+#              #
#    Updated: 2021/10/25 12:53:36 by sdzamari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_printf.c \
			srcs/ft_hex.c \
			srcs/ft_num.c \
			srcs/ft_char.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall

%.o: %.c
		gcc -c $(CFLAGS) -I includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)
	
clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean:
		$(MAKE) fclean -C ./libft
		rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re