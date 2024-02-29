/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize_single.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:49:41 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/29 20:22:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>

#define _PARAN_TYPES "()[]{}"

static t_token	*msh_ast_tokenize_paran_type(const char *line, size_t *cursor)
{
	char	c;

	c = line[*cursor];
	if (c == '(')
		return (msh_ast_tkn_new(TKN_PAREN_OPEN, NULL));
	else if (c == ')')
		return (msh_ast_tkn_new(TKN_PAREN_CLOSE, NULL));
	else if (c == '[')
		return (msh_ast_tkn_new(TKN_BRACKET_OPEN, NULL));
	else if (c == ']')
		return (msh_ast_tkn_new(TKN_BRACKET_CLOSE, NULL));
	else if (c == '{')
		return (msh_ast_tkn_new(TKN_BRACE_OPEN, NULL));
	else if (c == '}')
		return (msh_ast_tkn_new(TKN_BRACE_CLOSE, NULL));
	return (NULL);
}

t_token	*msh_ast_tokenize_single(const char *line, size_t *cursor)
{
	char	c;
	t_token	*token;

	c = line[*cursor];
	if (c == ' ')
		token = msh_ast_tkn_new(TKN_SPACE, NULL);
	else if (c == '\n')
		token = msh_ast_tkn_new(TKN_NEWLINE, NULL);
	else if (c == ';')
		token = msh_ast_tkn_new(TKN_SEMICOLON, NULL);
	else if (ft_strchr(_PARAN_TYPES, c))
		token = msh_ast_tokenize_paran_type(line, cursor);
	else if (c == '|')
		token = msh_ast_tkn_new(TKN_PIPE, NULL);
	else if (c == '&')
		token = msh_ast_tkn_new(TKN_BACKGROUND, NULL);
	else if (c == '<')
		token = msh_ast_tkn_new(TKN_REDIR_IN, NULL);
	else if (c == '>')
		token = msh_ast_tkn_new(TKN_REDIR_OUT, NULL);
	else
		return (NULL);
	return (token);
}
