/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:43:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 20:39:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <msh/env.h>
#include <msh/exec/exec.h>
#include <msh/io/path.h>

int	msh_exec(t_minishell *msh, char **argv, char **envp)
{
	pid_t	pid;
	int		status;

	status = -1;
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			ft_dprintf(2, "%s: %s: %m\n", msh->name, argv[0]);
	}
	else if (pid < 0)
		ft_dprintf(2, "%s: %s: %m\n", msh->name, argv[0]);
	else
	{
		if (waitpid(pid, &status, 0) < 0)
			ft_dprintf(2, "%s: %s: %m\n", msh->name, argv[0]);
	}
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

int	msh_exec_simple(t_minishell *msh, char **args)
{
	int		status;
	char	**env;

	env = msh_env_tab(msh);
	status = msh_exec(msh, args, env);
	msh_env_tab_free(env);
	return (status);
}
