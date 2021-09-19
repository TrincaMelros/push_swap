# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malmeida <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 10:29:03 by malmeida          #+#    #+#              #
#    Updated: 2021/09/19 11:00:47 by malmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	--quiet

			# Library Name #
NAME		=
PUSH_SWAP	=	push_swap

			# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

			# Mandatory Variables #
SRC_PUSH_SWAP	=	./srcs/*.c

			# Compiling Variables #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I./includes -I$(LIBFT_DIR) -I$(PRINTF_DIR)
RM		= rm -f

			# Color Variables #
GREEN		= \e[0;32m
RED			= \e[0;31m
YELLOW		= \e[0;33m
RESET		= \e[0m

all: $(PUSH_SWAP)

$(NAME): all

$(PUSH_SWAP): $(LIBFT) $(SRC_PUSH_SWAP)
	@ $(CC) $(CFLAG) $(SRC_PUSH_SWAP) $(LIBFT) -o $(PUSH_SWAP)
	@printf "[$(GREEN)SUCCESS$(RESET)] Push_Swap compiled.\n"

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(PUSH_SWAP)
	@printf "[$(YELLOW)SUCCESS$(RESET)] Executable removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(PUSH_SWAP)
	@printf "[$(YELLOW)SUCCESS$(RESET)] Library removed.\n"
	@printf "[$(YELLOW)SUCCESS$(RESET)] Executable removed.\n"

re: fclean all

mandatory:	$(PUSH_SWAP)
bonus:		mandatory

m:	mandatory
b: 	bonus
