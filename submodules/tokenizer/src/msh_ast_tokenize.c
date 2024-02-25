/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:40:00 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/25 19:33:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>
#include <msh/minishell.h>

__attribute__((unused))
static bool	msh_ast_append_tokens(
		const char *line,
		size_t *cursor,
		t_list **list
) {
	t_token	*token;

	(void) cursor;
	(void) line;
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
		token = msh_ast_tkn_new(TKN_EOF, NULL);
	else if (c == '\n')
		token = msh_ast_tkn_new(TKN_NEWLINE, NULL);
	else if (c == ';')
		token = msh_ast_tkn_new(TKN_SEMICOLON, NULL);
	else if (c == '(')
		token = msh_ast_tkn_new(TKN_LPAREN, NULL);
	else if (c == ')')
		token = msh_ast_tkn_new(TKN_RPAREN, NULL);
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
