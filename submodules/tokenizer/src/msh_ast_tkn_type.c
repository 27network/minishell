/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tkn_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:16:10 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/29 20:39:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/tokenizer.h>

const char	*msh_ast_tkn_type(t_token_type type)
{
	static const char	*types[] = {
	[TKN_WORD] = "TKN_WORD", [TKN_SPACE] = "TKN_SPACE", [TKN_PIPE] = "TKN_PIPE",
	[TKN_SEMICOLON] = "TKN_SEMICOLON", [TKN_AND_IF] = "TKN_AND_IF",
	[TKN_OR_IF] = "TKN_OR_IF", [TKN_BACKGROUND] = "TKN_BACKGROUND",
	[TKN_NEWLINE] = "TKN_NEWLINE", [TKN_EOF] = "TKN_EOF",
	[TKN_NUMBER] = "TKN_NUMBER", [TKN_ASSIGNMENT_WORD] = "TKN_ASSIGNMENT_WORD",
	[TKN_FD_REF] = "TKN_FD_REF", [TKN_REDIR_OUT] = "TKN_REDIR_OUT",
	[TKN_REDIR_OUT_CLOBBER] = "TKN_REDIR_OUT_CLOBBER",
	[TKN_REDIR_OUT_BOTH] = "TKN_REDIR_OUT_BOTH",
	[TKN_REDIR_APPEND] = "TKN_REDIR_APPEND", [TKN_REDIR_IN] = "TKN_REDIR_IN",
	[TKN_REDIR_HERE_DOC] = "TKN_REDIR_HERE_DOC",
	[TKN_REDIR_HERE_STR] = "TKN_REDIR_HERE_STR",
	[TKN_REDIR_WORD] = "TKN_REDIR_WORD", [TKN_REDIR_FD] = "TKN_REDIR_FD",
	[TKN_LPAREN] = "TKN_LPAREN", [TKN_RPAREN] = "TKN_RPAREN",
	[TKN_LBRACKET] = "TKN_LBRACKET", [TKN_RBRACKET] = "TKN_RBRACKET",
	[TKN_LBRACE] = "TKN_LBRACE", [TKN_RBRACE] = "TKN_RBRACE",
	[TKN_UNKNOWN] = "TKN_UNKNOWN",
	};

	return (types[type]);
}
