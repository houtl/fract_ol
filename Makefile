# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 17:35:06 by thou              #+#    #+#              #
#    Updated: 2017/04/05 16:09:53 by thou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		=	\033[30;1m
RED			=	\033[31;1m
GREEN		=	\033[32;1m
YELLOW		=	\033[33;1m
BLUE		=	\033[34;1m
PURPLE		=	\033[35;1m
CYAN		=	\033[36;1m
WHITE		=	\033[37;1m
RESET		=	\033[0m
CLEAR		=	\033[H\e[J

NAME		=	fdf
FLAG		=	-Wall -Werror -Wextra
FLAGMLX		=	-lmlx -framework OpenGL -framework Appkit
SRC_DIR		=	src/
SRC_BASE	=	fdf.c map.c image.c color.c print.c ligne.c key.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ_DIR		=	obj/
LIBFT		=	./libft
LFT			=	./libft/libft.a
LIBMLX		=	./minilibx_macos
LMLX		=	./minilibx_macos/libmlx.a
INCLUDES	=	-I./includes -I./libft/includes -I./minilibx_macos/
OBJ			=	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(LFT) $(LMLX) $(NAME)

$(LFT):
	@make -C $(LIBFT)

$(LMLX):
	@make -C $(LIBMLX)

$(NAME): $(OBJ)
	@gcc $(FLAG) $(OBJ) -o $(NAME) -L$(LIBFT) -lft -L$(LIBMLX) $(FLAGMLX) $(INCLUDES)
	@echo "\033[48;5;15;38;5;25;1mMAKE $(NAME) DONE$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAG) -o $@ -c $< $(INCLUDES)


clean:
	@make clean -C $(LIBMLX)
	@make clean -C $(LIBFT)
	@rm -rf obj

fclean: 
	@make fclean -C $(LIBFT)
	@make clean -C $(LIBMLX)
	@rm -rf obj
	@rm -rf $(NAME)
	@echo "$(YELLOW)Clean	fdf$(GREEN)			[ OK ]$(RESET)"

re: fclean all
