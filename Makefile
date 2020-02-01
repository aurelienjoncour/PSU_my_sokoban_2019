##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c			\
				$(SRC_DIR)my_sokoban.c		\
				$(SRC_DIR)map.c				\
				$(SRC_DIR)move_player.c		\
				$(SRC_DIR)game.c			\
				$(SRC_DIR)other.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_sokoban

CFLAGS		+=	-Wall -Wextra -I./include

LDLFLAGS	+= -L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIB_DIR)
			gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -lncurses -g

clean:
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(OBJ)

fclean:		clean
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

debugs:	fclean all
			gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -g

tests_run:	fclean
			make fclean -C tests/
			make -C tests/

.PHONY: all clean fclean re run debugs

bonus:		fclean
		make -C bonus/
