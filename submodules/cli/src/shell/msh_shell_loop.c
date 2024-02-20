/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:16:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 02:24:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#define MSH_CLI_UTILS
#include <msh/cli/cli.h>
#include <msh/cli/shell.h>
#include <msh/exec/exec.h>

static int	msh_debug_exec(t_minishell *msh, char *line)
{
	char	**array;
	size_t	i;
	int		ret;

	array = ft_splits(line, " \t\n\f");
	if (!array)
		return (-1);
	ret = msh_exec_simple(msh, array);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (ret);
}

static int	msh_handle_line(t_minishell *msh, char *line)
{
	if (*line)
		add_history(line);
	return (msh_debug_exec(msh, line));
}

void	msh_shell_loop(t_minishell *msh)
{
	char	*line;
	char	*prompt;
	int		ret;
	bool	interactive;

	interactive = msh_is_interactive();
	if (!interactive)
		rl_prep_term_function = 0;
	prompt = NULL;
	while (true)
	{
		if (interactive)
			prompt = msh_prompt_bash();
		line = readline(prompt);
		if (prompt)
			free(prompt);
		if (!line && interactive)
			ft_printf("exit\n");
		if (!line)
			break ;
		ret = msh_handle_line(msh, line);
		free(line);
		if (ret == -1)
			break ;
	}
}
