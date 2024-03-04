/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_defaults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:15:34 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 17:14:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/env.h>
#include <ft/string/parse.h>

static char	*_(char *s)
{
	return (ft_strdup(s));
}

static void	msh_setup_shlvl(t_minishell *msh)
{
	char	*shlvl;

	shlvl = msh_env_get(msh, "SHLVL");
	if (shlvl)
	{
		shlvl = ft_lltoa(ft_atoll(shlvl) + 1);
		if (!shlvl)
			shlvl = _("1");
		if (!shlvl)
			return ;
		ft_map_put(msh->env, _("SHLVL"), shlvl, &msh_env_node_free);
	}
	else
		ft_map_put(msh->env, _("SHLVL"), _("1"), &msh_env_node_free);
}

void	msh_env_defaults(t_minishell *msh)
{
	msh_env_populate(msh);
	msh_setup_shlvl(msh);
}

// ft_map_put(msh->env, _("PWD"), _("/"), &msh_env_node_free);
// ft_map_put(msh->env, _("OLDPWD"), _("/"), &msh_env_node_free);
// ft_map_put(msh->env, _("HOME"), _("/"), &msh_env_node_free);
// ft_map_put(msh->env, _("PATH"), _("/bin:/usr/bin"), &msh_env_node_free);
