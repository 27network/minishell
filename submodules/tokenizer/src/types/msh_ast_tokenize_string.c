/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:44:46 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/25 19:43:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>

t_token	*msh_ast_tokenize_string(const char *line, size_t *cursor)
{
	t_token	*token;
	size_t	start;
	size_t	end;

	start = *cursor;
	end = start;
	while (line[end] && line[end] != '\'')
	{
		if (line[end] == '\\' && line[end + 1])
			end += 2;
		else
			end++;
	}
	if (line[end] == '\'')
	{
		end++;
		token = msh_ast_new_token(TKN_STRING, ft_strndup(line + start, end - start));
		*cursor = end;
	}
	else
		*cursor = end;
	return (token);
}
