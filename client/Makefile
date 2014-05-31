#******************************************************************************#
#                                                                               #
#                                                          :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                      +:+ +:+         +:+      #
#    by: acontass <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                  +#+#+#+#+#+   +#+            #
#    Created: 2014/01/28 10:43:27 by acontass           #+#    #+#              #
#    Updated: 2014/02/07 20:03:38 by lverniss         ###   ########.fr        #
#                                                                               #
#*******************************************************************************#
NAME	=	MiniTalk

SRCS	=	./src/main.c ./src/ft_atoi.c

SRC		=   $(addprefix $(SRCPATH), $(SRCS))

OBJ		=   $(SRC:.c=.o)

TEST		=	./src/main.o

CFLAGS	+=  -Wall -Wextra -Werror -I ./includes


all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $(SRC)
	@echo "\033[1;32m[ $(NAME) Created ]\033[1;32m"

clean :
	@if test -f $(TEST) ;then \
	rm -f $(OBJ) && echo "\033[1;32m[ OBJCLEAN : DONE ]\033[1;32m"; \
	else echo "\033[1;31m[ OBJCLEAN : file not exist ]\033[1;31m"; \
	fi

fclean : clean
	@if test -e $(NAME) ;then \
	rm -f $(NAME) && echo "\033[1;32m[ BINCLEAN : DONE ]\033[1;32m"; \
	else echo "\033[1;31m[ BINCLEAN : file not exist ]\033[1;31m"; \
	fi

re: fclean all

.PHONY: all clean fclean re
