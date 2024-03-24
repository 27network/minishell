# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2024/03/23 21:49:39 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE			=	make --debug=none --no-print-directory

CONFIG_MK		=	config/config.mk
NAME			=	$(shell $(MAKE) -f $(CONFIG_MK) print_PROJECT_NAME)
VERSION			=	$(shell $(MAKE) -f $(CONFIG_MK) print_PROJECT_VERSION)
EXTRA_DEBUG		=	$(shell $(MAKE) -f $(CONFIG_MK) print_EXTRA_DEBUG)
COMP_MODE		?=	"MANDATORY_MSH"

CWD				?=	$(shell pwd)
SUBMODULES		=	submodules

LIBFT_DIR		=	$(CWD)/third-party/libft
LIBFT			=	$(LIBFT_DIR)/libft.so

CACHE_DIR_NAME	=	.cache
CACHE_DIR		=	$(addprefix $(shell pwd)/, $(CACHE_DIR_NAME))

FEATURES_H		=	$(SUBMODULES)/shared/include/msh/features.h
FEATURES_H_ACTUAL=	config/features.h
FEATURES_H_GEN	=	config/features.h.gen.sh

MAIN_MODULE		=	cli
MAIN_MODULE_OUT	=	$(shell $(MAKE) -C $(SUBMODULES)/$(MAIN_MODULE) print_OUTPUT)
CLI_EXEC		=	$(CWD)/$(MAIN_MODULE_OUT)

DEPENDENCY_TREE	=	$(shell $(MAKE) -C $(SUBMODULES)/$(MAIN_MODULE) printdeptree)
D_FILES			:=	$(foreach dep, $(DEPENDENCY_TREE), $(shell $(MAKE) -C $(SUBMODULES)/$(dep) printdepfiles CACHE_DIR="$(CACHE_DIR)"))

RM				=	rm -rf

# Colors
TPUT			:=	tput -Txterm-256color
BLUE			:=	$(shell $(TPUT) setaf 4)
GRAY			:=	$(shell $(TPUT) setaf 8)
BOLD 			:=  $(shell $(TPUT) bold)
RED				:=	$(shell $(TPUT) setaf 1)
RESET			:=	$(shell $(TPUT) sgr0)
GREEN			:=	$(shell $(TPUT) setaf 2)
BOLD_WHITE		:=	$(RESET)$(BOLD)

AUTHORS			=	$(shell paste -s -d ':' config/author | rev | sed -e 's/\:/ \& /' -e 's/:/ ,/g' | rev) 
VG_RUN			?=

# multiline BANNER
define BANNER
 $(BLUE)               $(BOLD_WHITE)    $(RED)__  
 $(BLUE)   ____ ___  $(BOLD_WHITE)_____$(RED)/ /_ 
 $(BLUE)  / __ `__ \$(BOLD_WHITE)/ ___$(RED)/ __ \  
 $(BLUE) / / / / / $(BOLD_WHITE)(__  )$(RED) / / /
 $(BLUE)/_/ /_/ /_$(BOLD_WHITE)/____/$(RED)_/ /_/  $(RESET)v$(VERSION)
             by $(AUTHORS)
endef

_DISABLE_CLEAN_LOG := 0
_DISABLE_BANNER := 0

all:	 _banner $(NAME) 

build:	all clean

-include $(D_FILES)

_banner:
	@if [ $(_DISABLE_BANNER) -eq 0 ]; then \
		printf "$(info $(BANNER))"; \
		printf "⚙️ Compilation mode: $(COMP_MODE)"; \
		if [ $(EXTRA_DEBUG) -eq 1 ]; then \
			printf " ($(RED)Debug Mode$(RESET))"; \
		fi; \
		printf "\n\n"; \
	fi
	$(eval _DISABLE_BANNER := 1)

# invalidation mechanism
$(CACHE_DIR)/%:
	@if [ $(findstring .c, $<) ]; then \
		rm -rf $@; \
	fi

$(CLI_EXEC):
	@printf "\33[2K\r🛠️  Making $(BOLD_WHITE)$(NAME)$(RESET)\n"
	@$(MAKE) -C $(SUBMODULES)/$(MAIN_MODULE) DEPTH="1" CACHE_DIR="$(CACHE_DIR)" LIBFT_DIR="$(LIBFT_DIR)" # 3>/dev/null 2>&3

$(NAME): $(CONFIG_MK) $(FEATURES_H_ACTUAL) $(FEATURES_H) $(LIBFT) $(CLI_EXEC)
	@printf "⛓ Linking $(CLI_EXEC) -> $(NAME)"
	@cp -f "$(CLI_EXEC)" "$(NAME)"
	@printf "\33[2K\r✅ Linked $(BOLD_WHITE)$(NAME)$(RESET), enjoy this dumb madness.\n"

$(LIBFT):
	@printf "🛠️  Making libft\n"
	@$(MAKE) -C $(LIBFT_DIR) -j 
	@printf "\033[1A\33[2K\r✅ Built $(BOLD_WHITE)libft$(RESET)\n"

$(FEATURES_H_ACTUAL): $(FEATURES_H_GEN)
	@printf "✍  Generating $(FEATURES_H_ACTUAL)\n"
	@$(MAKE) -C config -f features.mk gen

$(FEATURES_H):
	@printf "⛓  Linking $(FEATURES_H) -> $(FEATURES_H_ACTUAL)\n"
	@$(MAKE) -C config -f features.mk genlink 

bonus:
	@$(MAKE) COMP_MODE="BONUS_MSH" re

extras:
	@$(MAKE) COMP_MODE="EXTRAS" re

42sh:
	@$(MAKE) COMP_MODE="MANDATORY_42SH" re

42sh-bonus:
	@$(MAKE) COMP_MODE="BONUS_42SH" re

remake: clean all

_fclean_prelude:
	@printf "🧹 Cleaned $(BOLD_WHITE)$(NAME)$(RESET) $(GRAY)(./$(NAME))$(RESET)\n"
	$(eval _DISABLE_CLEAN_LOG := 1)

clean:
	@if [ $(_DISABLE_CLEAN_LOG) -eq 0 ]; then printf "🧹 Cleaned $(BOLD_WHITE)$(NAME)$(RESET) $(GRAY)(./$(CACHE_DIR_NAME))$(RESET)\n"; fi
	@$(RM) $(CACHE_DIR)
	@if [ $(_DISABLE_CLEAN_LOG) -eq 0 ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi 

fclean:			_fclean_prelude clean
	@$(RM) $(FEATURES_H_ACTUAL)
	@$(RM) $(FEATURES_H)

	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re:				_banner fclean all

valgrind:		$(NAME)
	valgrind --suppressions=config/valgrind.vsupp -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes -q ./$(NAME) $(VG_RUN)

.PHONY:			all bonus remake clean fclean re valgrind _fclean_prelude _banner
