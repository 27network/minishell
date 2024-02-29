/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_ast_tkn_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:50:51 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/29 16:09:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/ast/tokenizer.h>
#include <stdio.h>

void	msh_ast_tkn_print(t_token *token)
{
	printf("{ type: %s", msh_ast_tkn_type(token->type));
	if (token->value)
		printf(", value: %s", (char *) token->value);
	if (token->data)
	{
		if (token->type == TKN_WORD)
			printf(", data: %s", (char *) token->data);
		else
			printf(", data: %p", token->data);
	}
	printf(" }\n");
}
