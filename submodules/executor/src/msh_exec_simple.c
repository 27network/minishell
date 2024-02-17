/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:43:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 10:38:54 by kiroussa         ###   ########.fr       */
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
			ft_printf("%s: %s: %m\n", msh->name, args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_printf("%s: %s: %m\n", msh->name, args[0]);
	else
		waitpid(pid, &status, 0);
	return (status);
}
