# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/03/15 19:07:21 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_SHARED		= arg_parcer.c instructions.c instructions2.c instructions3.c\
				  tools.c do_operation.c
SRCS_CHECKER	= main.c
SRCS_PUSH_SWAP	= main.c tools.c rot_to.c sort_5.c insertion_rot.c

OBJS_SHARED		= $(addprefix shared_srcs/, ${SRCS_SHARED:.c=.o})
OBJS_CHECKER	= $(addprefix checker_srcs/, ${SRCS_CHECKER:.c=.o})
OBJS_PUSH_SWAP	= $(addprefix push_swap_srcs/, ${SRCS_PUSH_SWAP:.c=.o})

.c.o:
			@echo Compiling: $<
			@clang -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o}

all:		checker push_swap

checker:	libft ${OBJS_CHECKER} ${OBJS_SHARED}
			@echo Linking program...
			@clang -Wall -Wextra -Werror -g -o ./checker ${OBJS_CHECKER} ${OBJS_SHARED} -L./libft -lft

push_swap:	libft ${OBJS_PUSH_SWAP} ${OBJS_SHARED}
			@echo Linking program...
			@clang -Wall -Wextra -Werror -g -o ./push_swap ${OBJS_PUSH_SWAP} ${OBJS_SHARED} -L./libft -lft

libft:
			@echo compiling libft...
			@make -sC ./libft libft.a


clean:
			@echo CLeaning OBJS and tests...
			@make -sC ./libft fclean
			@rm -f ${OBJS_CHECKER} ${OBJS_SHARED} ${OBJS_PUSH_SWAP}
fclean:		clean
			@echo CLeaning program...
			@rm -f checker push_swap

re:			fclean all

.PHONY:		all clean fclean re libft 
