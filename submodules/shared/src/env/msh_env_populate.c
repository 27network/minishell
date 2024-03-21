/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_populate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:49:59 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/21 22:06:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>

int	msh_env_populate(t_minishell *msh, const char **envp)
{
	char		*key;
	char		*value;
	size_t		i;
	size_t		index;

	i = 0;
	while (envp[i])
	{
		index = ft_strchr(envp[i], '=') - envp[i];
		key = ft_strndup(envp[i], index);
		if (!key)
			return (0);
		value = ft_strdup(envp[i] + index + 1);
		if (!value)
			free(key);
		if (!value)
			return (0);
		ft_map_put(msh->env, key, value, &msh_env_node_free);
		i++;
	}
	return (1);
}
