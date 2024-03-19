/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:57:31 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/16 01:27:32 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

typedef enum e_token_type
{
	TKN_WORD = 0,			// any sequence of characters
	TKN_SPACE,				// ' ' or '\t'
	TKN_PIPE,				// '|'
	TKN_SEMICOLON,			// ';'
	TKN_BACKGROUND,			// '&'
	TKN_NEWLINE,			// '\n'
	TKN_EOF,				// end of file
	TKN_REDIR_OUT,			// '>'
	TKN_REDIR_IN,			// '<'
	TKN_LPAREN,				// '('
	TKN_RPAREN,				// ')'
	TKN_LBRACE,				// '{'
	TKN_RBRACE,				// '}'
	TKN_LBRACKET,			// '['
	TKN_RBRACKET,			// ']'
	TKN_ASSIGN,				// '='
	____TKN_SEP,			// separator between Pure and Compound tokens
	TKN_ASSIGNMENT_WORD,	// any sequence of characters of the form name=value
	TKN_AND_IF,				// '&&'
	TKN_OR_IF,				// '||'
	TKN_REDIR_APPEND,		// '>>'
	TKN_REDIR_HERE_DOC,		// '<<' or '<<-'
	____DUMB_SEP,
	TKN_FD_REF,				// '&[n]' or '&[n]-'
	TKN_REDIR_OUT_CLOBBER,	// '>|'
	TKN_REDIR_HERE_STR,		// '<<<'
	TKN_REDIR_WORD,			// '<>'
	TKN_UNKNOWN,			// any other character
}	t_token_type;

const char	*msh_ast_tkn_type(t_token_type type);

typedef struct s_tkn_assign_data
{
	char	*key;
	char	*value;
}	t_tkn_assign_data;

#endif // TOKENS_H
