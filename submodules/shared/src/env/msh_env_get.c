/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:58:05 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 17:02:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>

char	*msh_env_get(t_minishell *msh, const char *key)
{
	if (ft_map_contains(msh->env, (void *)key))
		return (ft_map_get(msh->env, (void *)key));
	return (NULL);
}
