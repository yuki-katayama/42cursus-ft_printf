# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2020/11/23 19:11:41 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a

GCC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

INCDIR	=	./includes

SRCDIR	=	./srcs

LIBFT = srcs/libft

SRCS_LIST	= 	ft_printf.c \
			ft_printf_flag.c \
			ft_print_c.c \
			ft_print_s.c \
			ft_print_s_null.c \
			ft_print_percent.c \
			ft_print_int.c \
			ft_print_unsigned.c \
			ft_print_unsigned_long.c \
			ft_printf_utils.c \
			ft_printf.c \
			ft_initialize.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_LIST))

OBJS	=	$(SRCS:.c=.o)


.c.o:
			$(CC) $(CFLAGS)	-I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
				make -C $(LIBFT)
				echo Compiling $(NAME)
				cp srcs/libft/libft.a ./$(NAME)
				ar -rcs $(NAME) $(OBJS)
				echo ====DONE====

all:		$(NAME)

clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT)

fclean:		clean
				$(RM) $(NAME)
				make fclean -C $(LIBFT)

re:			fclean all

.PHONY: clean fclean all re