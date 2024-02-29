/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:40:00 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/29 16:00:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOKENIZER_TYPES
#include <msh/ast/tokenizer.h>
#include <msh/minishell.h>

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
		token = msh_ast_tokenize_string(line, cursor);
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
		token = msh_ast_tkn_new(TKN_UNKNOWN, NULL);
	// token = msh_ast_tokenize_word(line, cursor, list);
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
		if (!msh_ast_try_tokenize(input, &cursor, &list))
			errored = true;
		if (input[cursor] != '\0')
			cursor++;
	}
	if (errored)
		ft_lst_free(&list, (t_lst_dealloc) msh_ast_tkn_free);
	return (list);
}
