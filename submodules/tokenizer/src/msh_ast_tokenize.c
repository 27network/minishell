/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:40:00 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 18:17:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>
#include <msh/minishell.h>

static t_token	*msh_ast_build_token(t_token_type type, void *data)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->data = data;
	return (token);
}

static bool	msh_ast_append_tokens(
		const char *line,
		size_t *cursor,
		t_list **list
) {
	t_token	*token;

	token = NULL;
	if (!token)
		return (false);
	ft_lst_tadd(list, token);
	return (true);
}

/**
 * @brief Tries and tokenizes a string
 */
static bool	msh_ast_try_tokenize(
		const char *line,
		size_t *cursor,
		t_list **list
) {
	char	c;
	t_token	*token;

	c = line[*cursor];
	if (c == '\'' || c == '\"')
		token = msh_ast_tokenize_string(line, cursor, list, c == '\"');
	else if (c == 0)
		token = msh_ast_build_token(TKN_EOF, NULL);
	else if (c == '\n')
		token = msh_ast_build_token(TKN_NEWLINE, NULL);
	else if (c == ';')
		token = msh_ast_build_token(TKN_SEMICOLON, NULL);
	else if (c == '(')
		token = msh_ast_build_token(TKN_LPAREN, NULL);
	else if (c == ')')
		token = msh_ast_build_token(TKN_RPAREN, NULL);
	else
		token = msh_ast_tokenize_word(line, cursor, list);
	if (!token)
		return (false);
	ft_lst_tadd(list, token);
	return (true);
}

t_list	*msh_ast_tokenize(const char *input)
{
	t_list	*list;
	size_t	cursor;
	bool	errored;

	cursor = 0;
	list = NULL;
	errored = false;
	while (input[cursor] != '\0' && !errored)
	{
		if (ft_isspace(input[cursor]))
			cursor++;
		else if (!msh_ast_try_tokenize(input, &cursor, &list))
			errored = true;
	}
	if (errored)
		ft_lst_free(&list, (t_lst_dealloc) msh_ast_tkn_free);
	return (list);
}
