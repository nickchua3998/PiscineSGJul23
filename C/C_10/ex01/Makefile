SRC		= ft_cat.c aux.c

OBJ		= ${SRC:.c=.o}

NAME		= ft_cat

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} -o ${NAME} ${OBJ}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean

