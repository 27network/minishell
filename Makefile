# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/12 20:04:44 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell 

CACHE_DIR		= $(shell pwd)/.cache

all:			$(NAME)

$(NAME):
	@echo "Making minishell/submodules/cli"
	@make --no-print-directory -C submodules/cli all CACHE_DIR="$(CACHE_DIR)"
	@echo "Linking minishell/submodules/cli"
	@ln -sf submodules/cli/cli $(NAME)

bonus:
	@echo "Making minishell bonus"

clean:
	@echo "Cleaning minishell"
	@make --no-print-directory -C submodules/cli clean CACHE_DIR="$(CACHE_DIR)"

fclean:			clean
	@echo "Fcleaning minishell"
	@make --no-print-directory -C submodules/cli fclean CACHE_DIR="$(CACHE_DIR)"

re:				fclean all

.PHONY:			all bonus clean fclean re
