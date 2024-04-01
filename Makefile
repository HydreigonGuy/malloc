##
## EPITECH PROJECT, 2022
## my_malloc
## File description:
## Makefile
##

SRC		=	src/meta_data/create_meta_data.c	\
			src/meta_data/get_closest_size.c	\
			src/calloc/calloc.c	\
			src/free/free.c	\
			src/malloc/malloc.c	\
			src/malloc/check_for_already_allocated.c	\
			src/malloc/allocate_new_memory.c	\
			src/realloc/realloc.c	\
			src/reallocarray/reallocarray.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -Wall -fpic -shared $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	NAME all $(NAME) clean fclean re