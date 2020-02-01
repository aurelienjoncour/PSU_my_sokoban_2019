##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

SRC_DIR		=	../src/
INC_DIR		=	../include/
LIB_DIR		=	../lib/my

SRC		=	tests_game.c			\
			tests_sokoban.c			\
			tests_move.c			\
			tests_maps.c				\
			$(SRC_DIR)my_sokoban.c	\
			$(SRC_DIR)map.c			\
			$(SRC_DIR)move_player.c	\
			$(SRC_DIR)other.c		\
			$(SRC_DIR)game.c

OBJ		=	$(SRC:.c=.o)

NAME		=	test

CFLAGS		+=	-Wall -Wextra --coverage -I $(INC_DIR)

LDFLAGS		=	-L $(LIB_DIR) -lmy -lncurses --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR) --no-print-directory
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)
clean:
		rm -f $(OBJ)
		rm -f $(OBJ:.o=.gcno)
		rm -f $(OBJ:.o=.gcda)

fclean:		clean
		rm	-f	$(NAME)

re:		fclean all
