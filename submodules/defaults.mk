# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    defaults.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 05:36:04 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/22 21:47:59 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME	?= minishell
PROJECT_VERSION	?= 0.1.6

SRC_DIR			?= src
INCLUDE_DIR		?= include

CC				= clang
CFLAGS			= -Wall -Wextra -Werror -g3
DFLAGS 			= -MT $@ -MMD -MP -MF $(D_DIR)/$*.tmp.d

#LDFLAGS shouldn't be defined here, as it's shared with `ar`. 
# See `submodules/common-prelude.mk`

print_%:
	@echo $($*)
