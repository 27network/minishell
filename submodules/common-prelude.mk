# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    common-prelude.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 07:06:42 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/17 04:13:01 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	$(error NAME is not defined)
endif

NAME			?=	$(NAME) # you know what, fuck you, redefines your name

DEPTH			?=	0
SPACING			?=	$(shell printf "%$$(($(DEPTH)*4))s" "")
CACHE_DIR		?=	.cache
IS_EXEC			?=	0
LDFLAGS			?=

ifeq ($(IS_EXEC), 1)
	OUTPUT		?=	$(NAME)
	LD 			=	$(CC)
	LDFLAGS		+=	-lreadline
ifdef LIBFT_DIR
	LDFLAGS		+=	$(LIBFT_DIR)/build/output/libft.a
endif
else
	OUTPUT		?=	lib$(NAME).a
	LD			=	ar
	LDFLAGS		+=	rcs
	CFLAGS		+=	-nostdlib
endif

include ../defaults.mk

MODULE_CACHE	:=	$(CACHE_DIR)/$(NAME)
OBJ_DIR			?=	$(MODULE_CACHE)/obj
D_DIR			?=	$(MODULE_CACHE)/deps

CFLAGS			+=	-I$(INCLUDE_DIR)
ifdef LIBFT_DIR
	CFLAGS		+=	-I$(LIBFT_DIR)/include
endif

CFLAGS			+=	-DMINISHELL_DEFAULT_NAME="$(PROJECT_NAME)"
CFLAGS			+=	-DMINISHELL_VERSION="$(PROJECT_VERSION)"

ifdef DEPS
	TMPDEPDECL 	:= $(DEPS:%=-I../%/include)
	CFLAGS		+=	$(TMPDEPDECL)
endif

# static linking
LIBS :=
ifdef DEPS
	BUILD_NEW_ARRAY = $(eval LIBS += "$(CACHE_DIR)/$(shell echo "$(1)" | xargs)/lib$(shell echo "$(1)" | xargs).a")
	_ := $(foreach item, $(DEPS), $(call BUILD_NEW_ARRAY, $(item)))

	LDFLAGS		+=	$(LIBS:%=-Wl,--whole-archive %)
	LDFLAGS		+=	-Wl,--no-whole-archive
endif

OUTPUT			:=	$(addprefix $(MODULE_CACHE)/, $(OUTPUT))
