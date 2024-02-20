/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:55:20 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 22:07:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>

static void	msh_env_free(t_map_node *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	msh_destroy(t_minishell *msh)
{
	ft_map_free(&msh->env, msh_env_free);
	ft_lst_free(&msh->free_buffer, free);
}
