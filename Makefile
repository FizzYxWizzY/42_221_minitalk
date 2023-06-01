# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 19:05:58 by mflury            #+#    #+#              #
#    Updated: 2023/06/01 15:13:33 by mflury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra

SRC_SERVER = server.c \
			error.c \

SRC_CLIENT = client.c \
			error.c \


all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_SERVER)
	@echo Creating $(NAME_SERVER)
	@make -C printf/
	$(CC) $(OBJ_SERVER) $(CFLAGS) ./printf/libftprintf.a -o $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT)
	@echo Creating $(NAME_CLIENT)
	$(CC) $(OBJ_CLIENT) $(CFLAGS) ./printf/libftprintf.a -o $(NAME_CLIENT)

%.o : %.c
	@echo Creating objets files $<
	$(CC) $(CFLAGS) -Iprintf -c $< -o $@

clean :
	@echo Deleting objets files
	@make clean -C printf/
	@rm -f $(OBJ_SERVER)
	@rm -f $(OBJ_CLIENT)
	
fclean : clean 
	@echo Deleting others files
	@rm -f ./printf/libftprintf.a
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)

re : fclean all

.PHONY : clean fclean re
