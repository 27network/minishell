/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:34:00 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 07:38:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <ft/data/list.h>

typedef enum	e_msh_token_type
{
	WORD,
	PIPE,
	OPEN_PAR,
	CLOSE_PAR,
	SEMICOLON,
	REDIR_IN,
	REDIR_OUT,
	NEWLINE,
	END_OF_FILE,
}	t_msh_token_type;

typedef struct	s_msh_token
{
	t_msh_token_type	type;
	void				*data;
}	t_msh_token;

t_list			*msh_lexer_tokenize(char *input);

#endif // LEXER_H
