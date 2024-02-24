/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_handle_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:22:17 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 13:27:06 by kiroussa         ###   ########.fr       */
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
	t_list	*tokens;

	tokens = msh_ast_tokenize(line);
	if (!tokens)
		return (255);
	printf("Tokens:\n");
	ft_lst_foreach(tokens, (void (*)(void *)) & msh_ast_tkn_print);
	ft_lst_free(&tokens, (t_lst_dealloc) & msh_ast_tkn_free);
	return (msh_debug_exec(msh, line));
}
