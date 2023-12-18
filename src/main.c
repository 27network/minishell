/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:34:19 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/18 17:52:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <msh/shell/prompt.h>
#include <msh/signal.h>

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	(void) envp;
	msh_signal_init();
	msh_shell_prompt();
	clear_history();
	rl_clear_history();
	ft_putendl("exit");
	return (0);
}
