/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:44:46 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/26 14:08:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>

static size_t	msh_find_string_end(const char *line, size_t start)
{
	size_t	end;
	char	start_char;
	size_t	inners;

	end = start;
	inners = 0;
	start_char = line[start];
	while (line[end])
	{
		if (line[end] == start_char && inn
	}
	return (end);
}

t_token	*msh_ast_tokenize_string(const char *line, size_t *cursor)
{
	t_token	*token;
	size_t	start;
	size_t	end;

	start = *cursor;
	end = msh_find_string_end(line, start);
}
