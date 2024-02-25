/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_populate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:49:59 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 22:55:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>

void	msh_env_populate(t_minishell *msh)
{
	const char	**envp;
	char		*key;
	char		*value;
	size_t		i;
	size_t		index;

	i = 0;
	envp = msh->launch_args.envp;
	while (envp[i])
	{
		index = ft_strchr(envp[i], '=') - envp[i];
		key = ft_strndup(envp[i], index);
		if (!key)
			continue ;
		value = ft_strdup(envp[i] + index + 1);
		if (!value)
			free(key);
		if (!value)
			continue ;
		ft_map_put(msh->env, key, value, &msh_env_node_free);
		printf("%s=%s\n", key, value);
		i++;
	}
}
