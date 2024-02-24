/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tkn_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:50:51 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 13:22:46 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/tokenizer.h>
#include <stdio.h>

void	msh_ast_tkn_print(t_token *token)
{
	printf("{ type: %s, value: %s, data: %p }\n", msh_ast_tkn_type(token->type),
		token->value, token->data);
}
