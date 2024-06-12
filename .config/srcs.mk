# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:18:49 by mbrousse          #+#    #+#              #
#    Updated: 2024/06/07 17:08:54 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)		\
			$(ERROR)	\
			$(MATH)		\
			$(PARSING)	\
			$(MOVE)		\
			$(MINI_MAPS)\
			$(UTILS)

DIR_MAIN	=	main/

SRC_MAIN	=	main.c			\
				main_loop.c		\
				key_handler.c	\
				set_struct.c

MAIN	=	$(addprefix $(DIR_MAIN), $(SRC_MAIN))

DIR_ERROR	=	error/

SRC_ERROR	=	error.c\
				free.c

ERROR	=	$(addprefix $(DIR_ERROR), $(SRC_ERROR))

DIR_MATH	=	math/

SRC_MATH	=	raycasting2.c	\
				recast2.c	 	\
				recast.c		\
				calc_delta_dist.c

MATH	=	$(addprefix $(DIR_MATH), $(SRC_MATH))

DIR_PARSING	=	parsing/

SRC_PARSING	=	parse_map.c		\
				parse_line.c	\
				check_file.c	\
				check_data.c	\
				setup.c			\
				read_file.c 	\
				parse_texture.c	\
				check_data_utils.c


PARSING	=	$(addprefix $(DIR_PARSING), $(SRC_PARSING))


DIR_UTILS	=	utils/

SRC_UTILS	=	mlx_utils.c		  \
				parse_line_utils.c\
				check_map_utils.c \

UTILS	=	$(addprefix $(DIR_UTILS), $(SRC_UTILS))

DIR_MINI_MAPS	=	mini_maps/

SRC_MINI_MAPS	=	mini_map.c

MINI_MAPS	=	$(addprefix $(DIR_MINI_MAPS), $(SRC_MINI_MAPS))

DIR_MOVE	=	move/

SRC_MOVE	=	move_up.c	\
				move_down.c	\
				move_left.c	\
				move_right.c\
				rotate_left.c\
				rotate_right.c

MOVE	=	$(addprefix $(DIR_MOVE), $(SRC_MOVE))
