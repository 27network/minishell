/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:40:00 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/29 20:13:03 by kiroussa         ###   ########.fr       */
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

	printf("Trying to tokenize '%s' at %zu:\t", line + *cursor, *cursor);
	c = line[*cursor];
	if (c == '\\')
		token = msh_ast_tokenize_escape(line, cursor);
	else if (c == '\'' || c == '\"')
		token = msh_ast_tokenize_string(line, cursor);
	else if (c == '$')
		token = msh_ast_tokenize_variable(line, cursor);
	else if (ft_strchr(SINGLE_TOKENS, c) != NULL)
		token = msh_ast_tokenize_single(line, cursor);
	else
		token = msh_ast_tokenize_word(line, cursor);
	if (!token)
		printf("Failed");
	printf("\n");
	if (!token)
		return (false);
	msh_ast_tkn_print(token);
	ft_lst_tadd(list, token);
	return (true);
}

t_list	*msh_ast_tokenize(const char *input)
{
	t_list	*list;
	size_t	cursor;
	bool	errored;
	size_t	threshold;
	size_t	loops;

	cursor = 0;
	threshold = ft_strlen(input);
	loops = 0;
	list = NULL;
	errored = false;
	while (input[cursor] != '\0' && !errored)
	{
		if (!msh_ast_try_tokenize(input, &cursor, &list))
			errored = true;
		if (input[cursor] != '\0')
			cursor++;
		if (loops++ > threshold)
			errored = true;
	}
	if (errored)
		printf("Errored (at '%s':%zu)\n", input + cursor, cursor);
	if (errored)
		ft_lst_free(&list, (t_lst_dealloc) msh_ast_tkn_free);
	return (list);
}
