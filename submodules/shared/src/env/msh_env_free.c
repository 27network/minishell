/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:46:23 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 22:53:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>

void	msh_env_node_free(t_map_node *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	msh_env_free(t_minishell *msh)
{
	ft_map_free(&msh->env, msh_env_node_free);
}
