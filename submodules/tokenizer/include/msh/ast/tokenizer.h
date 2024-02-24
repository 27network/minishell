/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:36:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 04:41:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum e_token_type
{
	TKN_WORD,				// any sequence of characters
	TKN_PIPE,				// '|'
	TKN_SEMICOLON,			// ';'
	TKN_AND_IF,				// '&&'
	TKN_OR_IF,				// '||'
	TKN_BACKGROUND,			// '&'
	TKN_NEWLINE,			// '\n'
	TKN_EOF,				// end of file
	TKN_NUMBER,				// any sequence of digits
	TKN_ASSIGNMENT_WORD,	// any sequence of characters of the form name=value
	TKN_FD_REF,				// '&[n]'
	TKN_REDIR_OUT,			// '>'
	TKN_REDIR_OUT_CLOBBER,	// '>|'
	TKN_REDIR_OUT_BOTH,		// '>&' or '&>'
	TKN_REDIR_APPEND,		// '>>'
	TKN_REDIR_IN,			// '<'
	TKN_REDIR_HERE_DOC,		// '<<' or '<<-'
	TKN_REDIR_HERE_STR,		// '<<<'
	TKN_REDIR_WORD,			// '<>'
	TKN_REDIR_FD,			// '<&'
	//TKN_REDIR_FD_WORD,	// '<&[n]' or '<&[n]-'
	TKN_LBRACE,				// '{'
	TKN_RBRACE,				// '}'
	TKN_UNKNOWN,			// any other character
}	t_token_type;

typedef struct s_token_list
{
	t_token_type		type;
	char				*value;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_token_list;

t_token_list	*msh_ast_tokenize(const char *input);
void			msh_ast_tokens_free(t_token_list *list);

#endif // TOKENIZER_H
