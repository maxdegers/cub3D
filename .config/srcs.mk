# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:18:49 by mbrousse          #+#    #+#              #
#    Updated: 2024/05/24 11:41:51 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)		\
			$(ERROR)	\
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

DIR_PARSING	=	parsing/

SRC_PARSING	=	parse_map.c	\
				setup.c		\
				check_file.c

PARSING	=	$(addprefix $(DIR_PARSING), $(SRC_PARSING))


DIR_UTILS	=	utils/

SRC_UTILS	=	mlx_utils.c

UTILS	=	$(addprefix $(DIR_UTILS), $(SRC_UTILS))
