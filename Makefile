#******************************************************************************#
#                                                                               #
#                                                          :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                      +:+ +:+         +:+      #
#    by: acontass <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                  +#+#+#+#+#+   +#+            #
#    Created: 2014/01/28 10:43:27 by acontass           #+#    #+#              #
#    Updated: 2014/02/07 20:10:41 by lverniss         ###   ########.fr        #
#                                                                               #
#*******************************************************************************#
NAME = MiniTalk && MiniServer

all: $(NAME)

$(NAME): $(OBJ)
	make -C server
	make -C client
	cp server/MiniServer .
	cp client/MiniTalk .
	@echo "\033[1;32m[SUCCESS]\033[1;32m"

clean :
	make clean -C server
	make clean -C client
	@echo "\033[1;32m[SUCCESS]\033[1;32m"

fclean : clean
	make fclean -C server
	make fclean -C client
	rm -f MiniServer
	rm -f MiniTalk

re: fclean all

.PHONY: all clean fclean re
