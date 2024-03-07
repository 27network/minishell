/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:49:21 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/07 06:51:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>
#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>
#include <msh/features.h>
#include <stdlib.h>

static t_token	*msh_ast_build_assignment(char *key, char *value)
{
	t_tkn_assign_data	*data;

	data = ft_calloc(1, sizeof(t_tkn_assign_data));
	if (!data)
	{
		free(key);
		free(value);
		return (NULL);
	}
	data->key = key;
	data->value = value;
	return (msh_ast_tkn_new(TKN_ASSIGNMENT_WORD, data));
}

static t_token	*msh_ast_try_tokenize_assign(char *str)
{
	size_t				end;
	char				*key;
	char				*value;

	if (ft_strlen(str) == 0 || ft_strcmp(str, "=") == 0 || ft_isdigit(str[0]))
		return (msh_ast_tkn_new(TKN_WORD, str));
	end = 0;
	while (str[end] && str[end] != '=')
		end++;
	key = ft_strndup(str, end);
	if (key == NULL)
		free(str);
	if (key == NULL)
		return (NULL);
	value = ft_strdup(&str[end + 1]);
	free(str);
	if (value == NULL)
		free(key);
	if (value == NULL)
		return (NULL);
	return (msh_ast_build_assignment(key, value));
}

static t_token	*msh_ast_try_tokenize_typed(char *str)
{
	if (FEAT_TKN_INLINE_ENV_DEF && ft_strchr(str, '=') != NULL)
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
