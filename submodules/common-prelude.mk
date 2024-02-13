# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    common-prelude.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 07:06:42 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/12 22:47:31 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	$(error NAME is not defined)
endif

SUPERNAME	?=	minishell

NAME		?=	$(SUPERNAME)-$(NAME)

INCLUDE_DIR	?=	include
SRC_DIR		?=	src

CACHE_DIR	?=	.cache/$(NAME)
OBJ_DIR		?=	$(CACHE_DIR)/obj
D_DIR		?=	$(CACHE_DIR)/deps

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3
CFLAGS		+=	-I$(INCLUDE_DIR)

ifdef DEPS
	TMPDEPDECL := $(DEPS:%=-I../%/include)
	CFLAGS	+=	$(TMPDEPDECL)
endif

IS_EXEC		?=	0
ifeq ($(IS_EXEC), 1)
	OUTPUT	?=	$(NAME)
	LD 		=	$(CC)
	LDFLAGS	?=	-lreadline
else
	OUTPUT	?=	$(NAME).a
	LD		=	ar
	LDFLAGS	?=	rcs
endif
