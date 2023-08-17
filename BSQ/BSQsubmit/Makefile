SRC		= main.c check_map_valid.c ft_split.c str_func.c extract_map_tab.c ft_find_solution.c ft_print_solution.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE		= ./srcs/

HEAD		= ./includes/

NAME		= bsq

GCC		= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:		
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

