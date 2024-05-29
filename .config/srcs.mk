# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:18:49 by mbrousse          #+#    #+#              #
#    Updated: 2024/05/29 14:23:29 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)		\
			$(ERROR)	\
			$(MATH)		\
			$(PARSING)	\
			$(UTILS)

DIR_MAIN	=	main/

SRC_MAIN	=	main.c\
				main_loop.c

MAIN	=	$(addprefix $(DIR_MAIN), $(SRC_MAIN))

DIR_ERROR	=	error/

SRC_ERROR	=	error.c\
				free.c

ERROR	=	$(addprefix $(DIR_ERROR), $(SRC_ERROR))

DIR_MATH	=	math/

SRC_MATH	=	raycasting2.c

MATH	=	$(addprefix $(DIR_MATH), $(SRC_MATH))

DIR_PARSING	=	parsing/

SRC_PARSING	=	parse_map.c	\
				parse_line.c\
				check_file.c\
				check_data.c\
				setup.c		\
				read_file.c \
				parse_texture.c
				

PARSING	=	$(addprefix $(DIR_PARSING), $(SRC_PARSING))


DIR_UTILS	=	utils/

SRC_UTILS	=	mlx_utils.c		  \
				parse_line_utils.c\
				check_map_utils.c \

UTILS	=	$(addprefix $(DIR_UTILS), $(SRC_UTILS))
