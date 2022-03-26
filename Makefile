NAME				=	so_long

B_NAME				=	so_long_bonus

GAME				=	game

SRCS				=	main.c errors.c valid.c create_map.c player_items_fieldstruct.c other.c sprites_map_keys.c \
 						get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

B_SRCS				=	main_bonus.c errors_bonus.c valid_bonus.c create_map_bonus.c player_items_fieldstruct_bonus.c other_bonus.c sprites_map_keys_bonus.c \
                        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_sprite_show_sprites_bonus.c \
                        player_move_bonus.c player_coordinate_quarter_bonus.c enemy_move_bonus.c death_sees_player_bonus.c

G_SRCS				=	mega_game_bonus.c

CC					=	cc

FLAGS 				=	-W -W -W

MLX_FLAGS			=	-lmlx -framework OpenGL -framework AppKit

HEADER 				=	so_long_header.h

HEADER_B			=	so_long_header_bonus.h

OBJS				=	${SRCS:.c=.o}

B_OBJS				=	${B_SRCS:.c=.o}

G_OBJS				=	${G_SRCS:.c=.o}

LIBFT_PATH			=	./Libft/libft.a

MLX_MMS_PATH		=	./mlx/libmlx.a

%.o 				:	%.c		${HEADER}
						${CC} ${FLAGS} -c $< -o $@

all					:	make_libft ${NAME}

bonus				:	make_libft ${B_NAME} ${GAME}

make_libft			:
						${MAKE} -C ./Libft

${NAME}				:	${OBJS} ${LIBFT_PATH} ${MLX_MMS_PATH}
						${CC} ${FLAGS} ${LIBFT_PATH} ${OBJS} -I ${HEADER} ${MLX_FLAGS} -o $@

${B_NAME}			:	${B_OBJS} ${LIBFT_PATH} ${MLX_MMS_PATH}
						${CC} ${FLAGS} ${LIBFT_PATH} ${B_OBJS} -I ${HEADER_B} ${MLX_FLAGS} -o $@

${MLX_MMS_PATH}		:	make_mms

make_mms			:
						${MAKE} -C ./mlx/ libmlx.a

${GAME}				:   ${G_OBJS}
						${CC} ${FLAGS} ${G_OBJS} -o ${GAME}

clean				:
						rm -f ${OBJS} ${B_OBJS} ${G_OBJS}

fclean				:	clean
						rm -f ${NAME} ${B_NAME} ${GAME}
						cd ./Libft && make fclean
						cd ./mlx && make clean

re					:	fclean all


.PHONY				:	all clean fclean re bonus make_libft make_mms