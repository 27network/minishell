/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:16:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:19:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>

void	msh_shell_loop(t_minishell *msh)
{
	char	*line;
	char	*prompt;

	(void) msh;
	prompt = NULL;
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
