/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:40:00 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 05:38:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>
#include <msh/ast/tokenizer.h>
#include <stdlib.h>

t_token_list	*msh_ast_tokenize(const char *input)
{
	t_token_list	*tokens;
	t_token_list	*tmp;
	char			**split;
	size_t			i;

	tokens = NULL;
	split = ft_split(input, ' ');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		tmp = (t_token_list *)malloc(sizeof(t_token_list));
		if (!tmp)
			msh_ast_tokens_free(tokens);
		if (!tmp)
			return (NULL);
		tmp->value = split[i];
		tmp->next = tokens;
		if (tokens)
			tokens->prev = tmp;
		tokens = tmp;
		i++;
	}
	free(split);
	return (tokens);
}
