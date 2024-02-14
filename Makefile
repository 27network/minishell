# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/14 19:09:17 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell 

CACHE_DIR		= $(shell pwd)/.cache

# Colors
BLUE		:=	$(shell tput -Txterm setaf 4)
BOLD_WHITE	:=	$(shell tput -Txterm setaf 7)
RED			:=	$(shell tput -Txterm setaf 1)
RESET		:=	$(shell tput -Txterm sgr0)
GREEN		:=	$(shell tput -Txterm setaf 2)

# multiline BANNER
define BANNER
 $(BLUE)               $(BOLD_WHITE)    $(RED)__  
 $(BLUE)   ____ ___  $(BOLD_WHITE)_____$(RED)/ /_ 
 $(BLUE)  / __ `__ \$(BOLD_WHITE)/ ___$(RED)/ __ \  
 $(BLUE) / / / / / $(BOLD_WHITE)(__  )$(RED) / / /
 $(BLUE)/_/ /_/ /_$(BOLD_WHITE)/____/$(RED)_/ /_/  $(RESET)v0.0.1
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

_no_clean_log:
	$(set _DISABLE_CLEAN_LOG := 1)

clean:
ifneq ($(_DISABLE_CLEAN_LOG),1)
	@echo " Cleaning $(NAME)"
endif
	rm -rf $(CACHE_DIR)

fclean:			_no_clean_log clean
	@echo " F-Cleaning $(NAME)"
	

re:				fclean all

.PHONY:			all bonus clean fclean re
