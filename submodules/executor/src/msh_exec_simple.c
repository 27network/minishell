/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:43:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:38:26 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <msh/env.h>
#include <msh/exec/builtin.h>
#include <msh/exec/exec.h>
#include <msh/io/path.h>
#include <msh/externs.h>
#include <msh/signal.h> 

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

int	msh_exec(t_minishell *msh, char *binary_path, char **av, char **envp)
{
	pid_t	pid;
	int		status;

	status = -1;
	pid = fork();
	if (pid == 0)
	{
		msh_signal_setdfl();
		if (execve(binary_path, av, envp) == -1)
			msh_exec_error(msh, errno, av[0]);
		return (-1);
	}
	else if (pid < 0)
		ft_dprintf(2, "%s: %s: %m\n", msh->name, binary_path);
	else
	{
		if (waitpid(pid, &status, 0) < 0)
			ft_dprintf(2, "%s: %s: %m\n", msh->name, binary_path);
	}
	if (WCOREDUMP(status))
		ft_dprintf(2, "Quit (core dumped)\n");
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

int	msh_exec_builtin(t_minishell *msh, char **args, char **env)
{
	t_builtin	*builtin;
	bool		n_env;
	bool		n_msh;
	int			argc;

	builtin = msh_builtin_get(args[0]);
	if (builtin)
	{
		argc = 0;
		while (args[argc])
			argc++;
		n_env = (builtin->need & NEED_ENV) == NEED_ENV;
		n_msh = (builtin->need & NEED_MSH) == NEED_MSH;
		if (n_env && n_msh)
			return (builtin->func(argc, args, env, msh));
		else if (n_env)
			return (builtin->func(argc, args, env));
		else if (n_msh)
			return (builtin->func(argc, args, msh));
		else
			return (builtin->func(argc, args));
	}
	return (-1);
}

int	msh_exec_simple(t_minishell *msh, char **args)
{
	int		status;
	char	**env;
	char	*path;

	env = msh_env_tab(msh);
	status = msh_exec_builtin(msh, args, env);
	if (status != -1)
	{
		msh_env_tab_free(env);
		return (status);
	}
	if (!args[0])
		return (0);
	if (*args[0] != '.' && !ft_strchr(args[0], '/'))
		path = msh_resolve_path(msh, args[0]);
	else
		path = ft_strdup(args[0]);
	if (path)
	{
		status = msh_exec(msh, path, args, env);
		free(path);
	}
	msh_env_tab_free(env);
	return (status);
}
