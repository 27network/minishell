/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:43:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/07 09:57:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <msh/env.h>
#include <msh/exec/exec.h>
#include <msh/io/path.h>
#include <errno.h>

/**
 * This function checks if the given path is to a directory, which would result
 * in an error.
 * 
 * Since we don't have access to traditional stat or lstat, we'll use open in
 * a read-write mode first to check if errno is set to EISDIR. If it is, we'll
 * return an error. If it's not, we'll close the file descriptor try to reopen
 * it in read-only mode.
 *
 * @param path The path to check.
 */
static bool	msh_check_directory(const char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd < 0)
	{
		if (errno == EISDIR)
			return (true);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (false);
		(void) close(fd);
		return (false);
	}
	(void) close(fd);
	return (false);
}

static void	msh_exec_error(t_minishell *msh, int err, char *name)
{
	if (msh_check_directory(name))
		ft_dprintf(2, "%s: %s: %s\n", msh->name, name, strerror(EISDIR));
	else if (ft_strchr(name, '/'))
		ft_dprintf(2, "%s: %s: %s\n", msh->name, name, strerror(err));
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
	path = msh_resolve_path(msh, args[0]);
	if (path)
	{
		argv0 = args[0];
		args[0] = path;
		status = msh_exec(msh, args, env);
		args[0] = argv0;
		free(path);
	}
	msh_env_tab_free(env);
	return (status);
}
