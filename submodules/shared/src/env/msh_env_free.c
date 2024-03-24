/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:46:23 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 17:53:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>
#include <stdlib.h>

void	msh_env_node_free(t_map_node *node)
{
	if (node)
	{
		if (node->key)
			free(node->key);
		if (node->value)
			free(node->value);
		free(node);
	}
}

void	msh_env_free(t_minishell *msh)
{
	if (msh->env)
		ft_map_free(&msh->env, msh_env_node_free);
}
