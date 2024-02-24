/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tkns_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 04:42:13 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 13:19:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/tokenizer.h>
#include <stdlib.h>

void	msh_ast_tkn_free(t_token *token)
{
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	if (token->data)
		free(token->data);
	free(token);
}
