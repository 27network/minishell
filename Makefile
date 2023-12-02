# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/12/03 00:03:03 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRC		= libft
LIBFT			= $(LIBFT_SRC)/build/output/libft.a

NAME			= minishell 

INCLUDES		= ./include
SRC_FOLDER		= src

SRC_FILES		= 	shell/msh_shell_prompt.c \
					signal/msh_signal_init.c \
					signal/msh_signal_handler.c \
					main.c

SRC_FILES		:=	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
OBJ_FILES		=	$(SRC_FILES:.c=.o)

CC				= clang
CFLAGS			= -Wall -Wextra -Werror -g3
COPTS			= -I $(INCLUDES) -I $(LIBFT_SRC)/include

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(COPTS) $(OBJ_FILES) -o $(NAME) -lreadline $(LIBFT)

setup_bonus:
	$(eval CFLAGS += -DMSH_BONUS=1)

bonus:			setup_bonus $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(COPTS) $(OBJ_FILES) -o $(NAME) -lreadline $(LIBFT)

$(LIBFT): 
	make -C $(LIBFT_SRC) -j$(shell nproc) CFLAGS="$(CFLAGS)"

%.o:			%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	make -C $(LIBFT_SRC) clean
	rm -f $(COMMON_OBJ) $(PS_OBJ) $(CHECKER_OBJ)

fclean:			clean
	make -C $(LIBFT_SRC) fclean
	rm -f $(NAME) $(BONUS_NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re
