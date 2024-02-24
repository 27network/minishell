/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:43:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 12:56:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/exec/exec.h>

int	msh_exec_simple(t_minishell *msh, char **args)
{
	pid_t	pid;
	int		status;

	status = -1;
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			printf("%s: %s: execve: %m\n", msh->name, args[0]);
	}
	else if (pid < 0)
		printf("%s: %s: fork: %m\n", msh->name, args[0]);
	else
	{
		if (waitpid(pid, &status, 0) < 0)
			printf("%s: %s: waitpid: %m\n", msh->name, args[0]);
	}
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}
