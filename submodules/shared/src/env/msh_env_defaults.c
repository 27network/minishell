/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_defaults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:15:34 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 16:39:07 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>
#include <ft/string/parse.h>

static char	*_(char *s)
{
	return (ft_strdup(s));
}

void	msh_env_defaults(t_minishell *msh)
{
	char	*shlvl;

	msh_env_populate(msh);
	shlvl = ft_map_get(msh->env, "SHLVL");
	if (shlvl)
	{
		shlvl = ft_lltoa(ft_atoll(shlvl) + 1);
		ft_map_put(msh->env, _("SHLVL"), shlvl, &msh_env_node_free);
	}
	else
		ft_map_put(msh->env, _("SHLVL"), _("1"), &msh_env_node_free);
	// ft_map_put(msh->env, _("PWD"), _("/"), &msh_env_node_free);
	// ft_map_put(msh->env, _("OLDPWD"), _("/"), &msh_env_node_free);
	// ft_map_put(msh->env, _("HOME"), _("/"), &msh_env_node_free);
	// ft_map_put(msh->env, _("PATH"), _("/bin:/usr/bin"), &msh_env_node_free);
}
