# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzakharc <hzakharc@student.42wolfsburg>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 13:58:02 by hzakharc          #+#    #+#              #
#    Updated: 2024/12/03 20:07:13 by hzakharc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		=	src
SRCS		=	$(SRCSDIR)/main.c $(SRCSDIR)/map.c $(SRCSDIR)/error.c $(SRCSDIR)/map_utils.c \
				$(SRCSDIR)/utils.c $(SRCSDIR)/game.c $(SRCSDIR)/movement.c

LIBFTDIR	=	include/libft
PRINTFDIR	=	include/ft_printf
GNLDIR		=	include/gnl
MLXDIR		=	include/minilibx-linux

LIBS		=	$(GNLDIR)/gnl.a $(LIBFTDIR)/libft.a $(PRINTFDIR)/libftprintf.a $(MLXDIR)/libmlx.a

OBJS		=	$(SRCS:.c=.o)

CC			=	@cc
RM			=	@rm -f
CCFLAGS		=	-Wall -Werror -Wextra -Iinclude/mlx
MLXFLAGS	=	-L/usr/X11/lib -lX11 -lXext -Llibs/mlx_linux -lm

BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\e[0;33m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

CLEAR		=	\033c

SUCCESS		=	@echo "$(YELLOW)so_long compiled successfully$(COLOR)"
S_OBJS		=	@echo "$(BLUE)cleaning of objects completed <(￣︶￣)>$(COLOR)"
S_NAME		=	@echo "$(CYAN)full clean completed ! ヽ(・∀・)ﾉ$(COLOR)"

NAME		=	so_long

%.o:		%.c
			$(CC) $(CCFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -sC $(LIBFTDIR)
			@make -sC $(PRINTFDIR)
			@make -sC $(GNLDIR)
			@make --no-print-directory -sC $(MLXDIR)
			@$(CC) $(CCFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)
			$(SUCCESS)

clean:
			$(RM) $(OBJS)
			@make --no-print-directory -sC $(LIBFTDIR) clean
			@make --no-print-directory -sC $(PRINTFDIR) clean
			@make --no-print-directory -sC $(GNLDIR) clean
			@make --no-print-directory -sC $(MLXDIR) clean
			$(S_OBJS)

fclean:		clean
			$(RM) $(NAME)
			@make --no-print-directory -sC $(LIBFTDIR) fclean
			@make --no-print-directory -sC $(PRINTFDIR) fclean
			@make --no-print-directory -sC $(GNLDIR) fclean
			$(RM) $(MLXDIR)/libmlx.a
			$(S_NAME)

re:			fclean all

.PHONY:		all clean fclean re
