/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_handle_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:22:17 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 05:34:59 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/tokenizer.h>
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

int	msh_handle_line(t_minishell *msh, char *line)
{
	t_token_list	*tokens;
	t_token_list	*tmp;

	tokens = msh_ast_tokenize(line);
	if (!tokens)
		return (255);
	printf("Tokens:\n");
	tmp = tokens;
	while (tmp)
	{
		ft_printf(" - '%s'\n", tmp->value);
		tmp = tmp->next;
	}
	msh_ast_tokens_free(tokens);
	return (msh_debug_exec(msh, line));
}
