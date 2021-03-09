# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/03/09 19:10:26 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_CHECKER	= main.c arg_parcer.c

OBJS_CHECKER	= $(addprefix checker_srcs/, ${SRCS_CHECKER:.c=.o})

.c.o:
			@echo Compiling: $<
			@clang -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o}

checker:	libft ${OBJS_CHECKER}
			@echo Linking program...
			@clang -Wall -Wextra -Werror -g -o ./checker ${OBJS_CHECKER} -L./libft -lft
libft:
			@echo compiling libft...
			@make -sC ./libft libft.a

all:		checker

clean:
			@echo CLeaning OBJS and tests...
			@make -sC ./libft fclean
			@rm -f ${OBJS_CHECKER}
fclean:		clean
			@echo CLeaning program...
			@rm -f checker

re:			fclean all

.PHONY:		all clean fclean re libft mlx 
