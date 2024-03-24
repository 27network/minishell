/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:24:05 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 17:55:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/print.h>
#include <msh/minishell.h>
#include <msh/env.h>
#include <unistd.h>

static char	**msh_build_env(t_minishell *msh, t_list *keys)
{
	char	**env;
	size_t	i;

	env = ft_calloc(sizeof(char *), ft_lst_size(keys) + 1);
	if (!env)
		return (__environ);
	i = 0;
	while (keys)
	{
		env[i] = ft_format("%s=%s", keys->content,
				ft_map_get(msh->env, keys->content));
		if (!env[i])
		{
			msh_env_tab_free(env);
			return (__environ);
		}
		keys = keys->next;
		i++;
	}
	return (env);
}

char	**msh_env_tab(t_minishell *msh)
{
	t_list	*keys;
	char	**env;

	keys = ft_map_keys(msh->env);
	if (!keys)
		return (__environ);
	if (ft_lst_size(keys) == 0)
	{
		ft_lst_free(&keys, NULL);
		return (__environ);
	}
	env = msh_build_env(msh, keys);
	ft_lst_free(&keys, NULL);
	return (env);
}
