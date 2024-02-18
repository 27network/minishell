/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:16:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/18 20:52:31 by kiroussa         ###   ########.fr       */
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
	ft_printf("--- Executing ---\n");
	ret = msh_exec_simple(msh, array);
	ft_printf("---   Done    ---\n");
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (ret);
}

static int	msh_handle_line(t_minishell *msh, char *line)
{
	ft_printf("Read: '%s'\n", line);
	if (*line)
		add_history(line);
	return (msh_debug_exec(msh, line));
}

void	msh_shell_loop(t_minishell *msh)
{
	char	*line;
	char	*prompt;
	int		ret;

	if (!msh_is_interactive())
		rl_prep_term_function = 0;
	prompt = NULL;
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
		ret = msh_handle_line(msh, line);
		free(line);
		if (ret == -1)
			break ;
	}
}
