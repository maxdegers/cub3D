# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:12:25 by mpitot            #+#    #+#              #
#    Updated: 2024/05/18 12:16:42 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include .config/srcs.mk
include .config/display.mk

OBJS	=	$(SRCS:%.c=${OBJ_D}%.o)

SRC_D	=	srcs/

OBJ_D	=	.objs/

HEAD	=	includes/

NAME	=	minishell

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror -g3

all		:	libft .internal_separate2 ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.c Makefile includes/minishell.h includes/colors.h
	@$(call print_progress,$<)
	@${CC} ${FLAGS} -I${HEAD} -c $< -o $@
	@$(call update_progress,$<)

${NAME}	:	${OBJ_D} ${OBJS} libft/libft.a
	@$(call print_progress,$(NAME))
	@${CC} ${FLAGS} ${OBJS} -L./libft -lft -I${HEAD} -o ${NAME} -lm ${READLINE_LIB}
	@$(eval CHANGED=1)
	@$(call erase)
	@$(call done_and_dusted,$(NAME))

${OBJ_D}:
	@mkdir -p ${OBJ_D}
	@mkdir -p ${OBJ_D}main
	@mkdir -p ${OBJ_D}error
	@mkdir -p ${OBJ_D}parsing
	@mkdir -p ${OBJ_D}utils

libft	:
	@make --no-print-directory -C ./libft

clean	:
	@echo "Cleaning $(WHITE)[$(RED)libft$(WHITE)]...$(DEFAULT)"
	@make --no-print-directory -C ./libft clean
	@$(call separator)
	@echo "Cleaning $(WHITE)[$(RED)$(NAME)$(WHITE)]...$(DEFAULT)"
	@rm -rf ${OBJ_D}
	@echo "$(WHITE)[$(RED)$(OBJ_D)$(WHITE)] $(RED)deleted.$(DEFAULT)"

fclean	:
	@echo "F***ing-Cleaning $(WHITE)[$(RED)libft$(WHITE)]...$(DEFAULT)"
	@make --no-print-directory -C ./libft fclean
	@$(call separator)
	@echo "F***ing-Cleaning $(WHITE)[$(RED)$(NAME)$(WHITE)]...$(DEFAULT)"
	@rm -rf ${OBJ_D}
	@echo "$(WHITE)[$(RED)$(OBJ_D)$(WHITE)] $(RED)deleted.$(DEFAULT)"
	@rm -f ${NAME}
	@echo "$(WHITE)[$(RED)$(NAME)$(WHITE)] $(RED)deleted.$(DEFAULT)"

leak: all .internal_separate3
	@echo "$(MAGENTA)Valgrind $(WHITE)~ $(YELLOW)Flags:$(DEFAULT)"
	@echo "   $(YELLOW)-$(DEFAULT)Show Leak Kinds"
	@echo "   $(YELLOW)-$(DEFAULT)Track FDs"
	@echo "   $(YELLOW)-$(DEFAULT)Show Mismatched Frees"
	@echo "   $(YELLOW)-$(DEFAULT)Read Variable Information"
	@echo "   $(YELLOW)-$(DEFAULT)Leak check"
	@$(call separator)
	@valgrind	--show-leak-kinds=all \
				--track-fds=yes \
				--show-mismatched-frees=yes \
				--read-var-info=yes \
				--leak-check=full \
				./$(NAME)

re		:	fclean .internal_separate1 all

.PHONY	:	all clean fclean re libft leak

.NOTPARALLEL all:
	@if [ $(CHANGED) -eq 0 ]; then \
		echo "$(YELLOW)Nothing to be done for $(WHITE)[$(CYAN)$(NAME)$(WHITE)].$(DEFAULT)"; \
	fi

.internal_announce	:
	@echo "$(YELLOW)Compiling $(WHITE)[$(CYAN)minishell$(WHITE)]...$(DEFAULT)"
