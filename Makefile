# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/14 02:46:52 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell 

CACHE_DIR		= $(shell pwd)/.cache

# multiline BANNER
define BANNER
                   __  
   ____ ___  _____/ /_ 
  / __ `__ \/ ___/ __ \  
 / / / / / (__  ) / / /
/_/ /_/ /_/____/_/ /_/  v0.0.1
            by kiroussa & cglandus

endef

all:	 _banner $(NAME) 

_banner:
	$(info $(BANNER))

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
