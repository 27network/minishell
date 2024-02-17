/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:16:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 10:38:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#define MSH_CLI_UTILS
#include <msh/cli/cli.h>
#include <msh/cli/shell.h>
#include <msh/exec/exec.h>

static void	msh_handle_line(t_minishell *msh, char *line)
{
	char	**array;
	size_t	i;

	(void) msh;
	ft_printf("Read: '%s'\n", line);
	ft_printf("Executing...\n");
	array = ft_splits(line, " \t\n\r\v\f");
	if (!array)
		return ;
	msh_exec_simple(msh, array);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	msh_shell_loop(t_minishell *msh)
{
	char	*line;
	char	*prompt;

	(void)msh;
	prompt = NULL;
	if (!msh_is_interactive())
		rl_prep_term_function = 0;
	while (true)
	{
		if (msh_is_interactive())
			prompt = msh_prompt_bash();
		line = readline(prompt);
		if (prompt)
			free(prompt);
		if (!line)
			ft_printf("exit\n");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		msh_handle_line(msh, line);
		free(line);
	}
}
