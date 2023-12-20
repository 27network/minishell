/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:39:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 07:48:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/lexer.h>

static void	msh_lexer_skip_whitespaces(char **input)
{
	while (**input == ' ' || **input == '\t')
		(*input)++;
}

t_list	*msh_lexer_tokenize(char *input)
{
	t_list	*list;

	if (input == NULL)
		return (NULL);
	list = NULL;
	msh_lexer_skip_whitespaces(&input);
	while (*input)
	{
	}
	return (list);
}
