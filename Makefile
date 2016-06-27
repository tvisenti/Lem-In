# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/08 10:27:37 by tvisenti          #+#    #+#              #
#    Updated: 2016/06/27 15:57:01 by tvisenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = lem-in

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	lem_in.c\
			li_algo.c\
			li_make_link.c\
			li_parse.c\
			li_solve.c\

LIB_NAME =	li_lstadd.c\
			li_lstnew.c\
			li_strnlen.c\

INC_NAME =	lem-in.h\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@make -C libft
	@$(CC) $(FLAGS) -o $@ $^ libft/libft.a libft/ft_printf/libftprintf.a
	@echo "      _,  __, _, _    _ _, _"
	@echo "      |   |_  |\/|    | |\ |"
	@echo "      |_  |_  |  | ~~ | | \|"
	@echo "      ~~~ ~~~ ~  ~    ~ ~  ~"
	@echo "\033[1;34mlem_in\t\t\033[1;33mCompilation\t\033[0;32m-OK-\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m-OK-\033[0m"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m-OK-\033[0m"
	@cd ./libft && $(MAKE) fclean

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m-OK-\033[0m"
	@cd ./libft && $(MAKE) norme
