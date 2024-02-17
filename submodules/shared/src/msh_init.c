/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:45:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 04:55:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>

int	msh_init(t_minishell *msh, int argc, char **argv, char **envp)
{
	msh->name = argv[0];
	msh->launch_args.argc = argc;
	msh->launch_args.argv = (const char **)argv;
	msh->launch_args.envp = (const char **)envp;
	return (0);
}
