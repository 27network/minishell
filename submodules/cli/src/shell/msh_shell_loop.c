/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:16:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:48:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#define MSH_CLI_UTILS
#include <msh/cli/cli.h>

void	msh_shell_loop(t_minishell *msh)
{
	char	*line;
	char	*prompt;

	(void) msh;
	prompt = NULL;
	if (msh_is_interactive())
		prompt = "cool prompt> ";
	else
		rl_prep_term_function = 0;
	while (true)
	{
		line = readline(prompt);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		ft_printf("echoing '%s'\n", line);
		free(line);
	}
}
