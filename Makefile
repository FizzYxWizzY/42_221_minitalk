# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 23:31:40 by mflury            #+#    #+#              #
#    Updated: 2022/12/16 23:31:40 by mflury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
ft_print_csp.c \
ft_print_diuxx.c \

all : $(NAME)

$(NAME) : $(OBJ)
	@echo Creating static library
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@echo Creating objets files $<
	@$(CC) -o $@ -c $< $(CFLAGS)

clean :
	@echo Deleting objets files
	@rm -f $(OBJ)

fclean : clean
	@echo Deleting others files
	@rm -f $(NAME) $(NAME).tar.gz $(NAME).zip

re : fclean all

tar :
	@echo Creating TAR.GZ archive
	@tar -czvf $(NAME).tar.gz $(SRC) libft.h Makefile

zip :
	@echo Creating ZIP archive
	@zip -r $(NAME).zip $(SRC) libft.h Makefile

.PHONY : clean fclean re tar zip
