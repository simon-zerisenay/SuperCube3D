# makefile made for linux poop!!, ask the pro leader for mac and cheese version!!


.SILENT:

NAME = cub3D

# CFLAGS = -g3 -Wall -Werror -Wextra -lincludes -lglfw -lGL #to be used with opengl

CFLAGS = -Wall -Wextra -Werror -Iincludes -I/usr/include -Imlx_linux -O3 #to be used with opengl

CFLAGS_CMP = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

UTILS = ${addprefix utils/, utils0.c err_msg.c mem_utils.c free_heap.c}

PARSING = ${addprefix parsing/, chk_args.c quality_control.c map_arser.c}

# EXECUTION = ${addprefix execution/, execution.c init.c}

SRC = ${addprefix source/, main.c ${PARSING}}

HEADER = ${addprefix includes/, cub69d.h}

OBJS = ${SRC:c=o} ${UTILS:c=o}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS} ${HEADER} Makefile
	${CC} ${OBJS} ${CFLAGS_CMP} -o $@

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re