/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tkn_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:50:51 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/07 06:41:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/tokenizer.h>
#include <stdio.h>

void	msh_ast_tkn_print(t_token *token)
{
	printf("{ type: %s", msh_ast_tkn_type(token->type));
	if (token->data)
	{
		if (token->type == TKN_WORD)
			printf(", data: %s", (char *) token->data);
		else if (token->type == TKN_ASSIGNMENT_WORD)
			printf(", data: { %s=%s }", ((t_tkn_assign_data *)token->data)->key,
				((t_tkn_assign_data *)token->data)->value);
		else
			printf(", data: (void *) %p", token->data);
	}
	printf(" }\n");
}
