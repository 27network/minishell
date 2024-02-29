/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:49:21 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/29 19:57:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>

static t_token	*msh_ast_try_tokenize_assign(char *str)
{
	size_t	start;

	if (ft_strlen(str) == 0 || ft_strcmp(str, "=") == 0 || ft_isdigit(str[0]))
		return (msh_ast_tkn_new(TKN_WORD, str));
	start = 0;
	while (str[start] && ft_strchr(_LOWERCASE _UPPERCASE _DIGITS "_", str[start]))
		start++;
	return (NULL);
}

__attribute__((unused))
static t_token	*msh_ast_try_tokenize_typed(char *str)
{
	if (ft_strchr(str, '=') != NULL)
		return (msh_ast_try_tokenize_assign(str));
	return (msh_ast_tkn_new(TKN_WORD, str));
}

t_token	*msh_ast_tokenize_word(const char *line, size_t *cursor)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = *cursor;
	end = start;
	while (line[end] && ft_strchr(TOKEN_DELIMITERS, line[end]) == NULL)
		end++;
	str = ft_strndup(&line[start], end - start);
	if (str == NULL)
		return (NULL);
	*cursor = end - 1;
	return (msh_ast_try_tokenize_typed(str));
}
