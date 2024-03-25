# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    features.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:16:42 by kiroussa          #+#    #+#              #
#    Updated: 2024/03/23 04:10:11 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = features.h
SOURCE = features.h.gen.sh
TARGET = ../submodules/shared/include/msh/features.h

all: $(TARGET) $(NAME)

genlink: $(TARGET)

$(TARGET):
	ln -fs $(shell pwd)/$(NAME) $(TARGET)

gen: $(NAME)

$(NAME): $(SOURCE)
	bash $(SOURCE) > $(NAME)

.PHONY: all gen genlink
.SILENT:
