/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:43:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/09 23:57:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <msh/env.h>
#include <msh/exec/exec.h>
#include <msh/io/path.h>
#include <errno.h>

static void	msh_exec_error(t_minishell *msh, int err, char *name)
{
	if (ft_strchr(name, '/'))
	{
		if (msh_is_directory(name))
			ft_dprintf(2, "%s: %s: %s\n", msh->name, name, strerror(EISDIR));
		else
			ft_dprintf(2, "%s: %s: %s\n", msh->name, name, strerror(err));
	}
	else
		ft_dprintf(2, "%s: command not found\n", name);
}

int	msh_exec(t_minishell *msh, char **av, char **envp)
{
	pid_t	pid;
	int		status;

	status = -1;
	pid = fork();
	if (pid == 0)
	{
		if (execve(av[0], av, envp) == -1)
			msh_exec_error(msh, errno, av[0]);
	}
	else if (pid < 0)
		ft_dprintf(2, "%s: %s: %m\n", msh->name, av[0]);
	else
	{
		if (waitpid(pid, &status, 0) < 0)
			ft_dprintf(2, "%s: %s: %m\n", msh->name, av[0]);
	}
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

int	msh_exec_simple(t_minishell *msh, char **args)
{
	int		status;
	char	**env;
	char	*path;
	char	*argv0;

	status = -1;
	env = msh_env_tab(msh);
	argv0 = args[0];
	if (!argv0)
		return (0);
	if (argv0[0] != '.' && !ft_strchr(argv0, '/'))
		path = msh_resolve_path(msh, argv0);
	else
		path = ft_strdup(argv0);
	if (path)
	{
		args[0] = path;
		status = msh_exec(msh, args, env);
		args[0] = argv0;
		free(path);
	}
	msh_env_tab_free(env);
	return (status);
}
