# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 05:36:04 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/18 18:32:37 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME	?=	minishell
PROJECT_VERSION	?=	0.1.4

SRC_DIR			?=	src
INCLUDE_DIR		?=	include

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror -g3

print_%:
	@echo $($*)
