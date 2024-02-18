/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:46:03 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/18 19:35:28 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/system.h>
#include <msh/cli/cli.h>
#include <msh/cli/opt.h>
#include <msh/cli/shell.h>
#include <msh/cli/signal.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	minishell;
	int			ret;

	msh_signal_init();
	msh_init(&minishell, argc, argv, envp);
	ret = 0;
	if (argc == 1)
		msh_shell_loop(&minishell);
	else
		ret = msh_handle_opts(&minishell);
	if (msh_get_hostname())
		free(msh_get_hostname());
	return (ret);
}
