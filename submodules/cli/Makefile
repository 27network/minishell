# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 06:49:07 by kiroussa          #+#    #+#              #
#    Updated: 2024/03/21 15:05:46 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cli
#TODO: make it so that shared and builtins aren't required here since they could
# 	   be transitive dependencies from other deps
DEPS		=	tokenizer executor shared builtins
IS_EXEC		=	1

include ../common-prelude.mk

SRC			=	opt/msh_handle_opts.c \
				opt/msh_opt_command.c \
				opt/msh_opt_help.c \
				opt/msh_opt_version.c \
				runner/msh_run_file.c \
				runner/msh_run_script.c \
				runner/msh_runner_check.c \
				shell/processor/msh_handle_line.c \
				shell/prompt/msh_prompt_bash.c \
				shell/msh_shell_loop.c \
				cli.c

include ../common.mk
