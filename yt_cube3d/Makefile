.SILENT:

NAME = cub69d

CFLAGS = -Imlx -g3 -I includes

UTILS = ${addprefix utils/, map_maker.c blayer.c utils0.c ray_casta.c}

SAUCE = ${addprefix sauce/, main.c ${UTILS}}

OBJS = ${SAUCE:c=o}

# %.o: %.c
# 	${CC} ${CFLAGS} -c $< -o $@

# MLX:
# 	make -C mlx
# 	cp mlx/libmlx.a .

${NAME}: ${OBJS} #${MLX}
	${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}
#	make -C mlx clean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


