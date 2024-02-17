# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 06:49:07 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/17 05:20:19 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cli
DEPS		=	shared
IS_EXEC		=	1

include ../common-prelude.mk

SRC			=	opt/msh_handle_opts.c \
				opt/msh_opt_command.c \
				opt/msh_opt_help.c \
				opt/msh_opt_version.c \
				runner/msh_run_file.c \
				shell/msh_shell_loop.c \
				signal/msh_signal_handler.c \
				signal/msh_signal_init.c \
				utils/msh_fileno.c \
				utils/msh_is_interactive.c \
				cli.c

include ../common.mk
