# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:18:49 by mpitot            #+#    #+#              #
#    Updated: 2024/05/18 12:12:18 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)		\
			$(ERROR)	\
			$(PARSING)	\
			$(UTILS)

DIR_MAIN	=	main/

SRC_MAIN	=	main.c

MAIN	=	$(addprefix $(DIR_MAIN), $(SRC_MAIN))

DIR_ERROR	=	error/

SRC_ERROR	=	error.c
ERROR	=	$(addprefix $(DIR_ERROR), $(SRC_ERROR))

DIR_PARSING	=	parsing/

SRC_PARSING	=

PARSING	=	$(addprefix $(DIR_PARSING), $(SRC_PARSING))


DIR_UTILS	=	utils/

SRC_UTILS	=	

UTILS	=	$(addprefix $(DIR_UTILS), $(SRC_UTILS))