# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitor <aitor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 18:19:05 by aitlopez          #+#    #+#              #
#    Updated: 2022/12/27 17:30:02 by aitlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
SRC = ft_printf.c ft_printf_char.c ft_printf_str.c ft_printf_hex.c ft_printf_ptr.c ft_printf_decs.c ft_printf_u_itoa.c aux.c 

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h

RM = rm -f

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	@echo "$(NAME) cleaned!$(NC)"

re : fclean all

.PHONY = all clean fclean re
