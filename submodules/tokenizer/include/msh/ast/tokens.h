/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:57:31 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 21:23:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

typedef enum e_token_type
{
	//						// WOW
	TKN_WORD = 0,			// any sequence of characters
	TKN_SPACE,				// ' ' or '\t'
	TKN_PIPE,				// '|'
	TKN_SEMICOLON,			// ';'
	TKN_DOLLAR,				// '$'
	TKN_AMP,				// '&'
	TKN_NEWLINE,			// '\n'
	TKN_REDIR_OUT,			// '>'
	TKN_REDIR_IN,			// '<'
	TKN_LPAREN,				// '('
	TKN_RPAREN,				// ')'
	TKN_LBRACE,				// '{'
	TKN_RBRACE,				// '}'
	TKN_ASSIGN,				// '='\
	separator,				// -- Compound tokens -- 
	TKN_SUBST,				// substituable token $VAR, ${EXPR}, *[], $((math))
	TKN_ASSIGNMENT_WORD,	// any sequence of characters of the form name=value
	TKN_AND_IF,				// '&&'
	TKN_OR_IF,				// '||'
	TKN_FD_REF,				// '&[n]'
	TKN_REDIR_OUT_CLOBBER,	// '>|'
	TKN_REDIR_OUT_BOTH,		// '>&' or '&>'
	TKN_REDIR_APPEND,		// '>>'
	TKN_REDIR_HERE_DOC,		// '<<' or '<<-'
	TKN_REDIR_HERE_STR,		// '<<<'
	TKN_REDIR_WORD,			// '<>'
	TKN_REDIR_FD,			// '<&'
	//TKN_REDIR_FD_WORD,	// '<&[n]' or '<&[n]-'
	TKN_UNKNOWN,			// any other character
}	t_token_type;

const char	*msh_ast_tkn_type(t_token_type type);

typedef struct s_tkn_assign_data
{
	char	*key;
	char	*value;
}	t_tkn_assign_data;

#endif // TOKENS_H
