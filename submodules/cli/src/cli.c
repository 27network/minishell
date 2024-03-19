/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:46:03 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 23:06:39 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/system.h>
#include <msh/cli/opt.h>
#include <msh/cli/shell.h>
#include <msh/signal.h>

/**
 * TODO: Return code from exec loop
 */
int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	minishell;

	msh_signal_init();
	msh_init(&minishell, argc, argv, envp);
	if (argc != 1)
		msh_handle_opts(&minishell);
	msh_shell_loop(&minishell);
	msh_destroy(&minishell);
	return (minishell.exit_code);
}
