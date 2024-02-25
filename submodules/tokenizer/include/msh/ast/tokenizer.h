/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:36:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/25 19:43:59 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <ft/data/list.h>
# include <msh/ast/tokens.h>
# include <stdbool.h>

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	void				*data;
}	t_token;

t_list	*msh_ast_tokenize(const char *input);
void	msh_ast_tkn_print(t_token *token);
void	msh_ast_tkn_free(t_token *token);

t_token	*msh_ast_tkn_new(t_token_type type, void *data);

# ifdef TOKENIZER_TYPES

t_token	*msh_ast_tokenize_string(const char *line, size_t *cursor);
t_token	*msh_ast_tokenize_word(const char *line, size_t *cursor,
			t_list **tokens);

# endif // TOKENIZER_TYPES

#endif // TOKENIZER_H
