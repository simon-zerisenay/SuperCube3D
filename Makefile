.SILENT:

NAME = cub3D

CFLAGS = -g3 -Wall -Werror -Wextra -I includes

UTILS = ${addprefix utils/, utils0.c err_msg.c mem_utils.c}

PARSING = ${addprefix parsing/, chk_args.c quality_control.c}

# EXECUTION = ${addprefix execution/, }

SRC = ${addprefix source/, main.c ${PARSING}}

HEADER = ${addprefix includes/, cub69d.h}

OBJS = ${SRC:c=o} ${UTILS:c=o}

${NAME} : ${OBJS} ${HEADER} Makefile
	${CC} ${CFLAGS} ${OBJS} -o $@

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re