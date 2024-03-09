/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:45:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/07 03:53:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/system.h>
#include <msh/env.h>

static uint64_t	msh_string_hash(void *data)
{
	char		*str;
	uint64_t	hash;

	str = (char *) data;
	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash);
}

int	msh_init(t_minishell *msh, int argc, char **argv, char **envp)
{
	ft_bzero(msh, sizeof(t_minishell));
	msh->name = argv[0];
	msh->launch_args.argc = argc;
	msh->launch_args.argv = (const char **) argv;
	msh->launch_args.envp = (const char **) envp;
	msh->interactive = msh_is_interactive();
	msh->env = ft_map_new(100, msh_string_hash,
			(t_map_cmp_function *) &ft_strcmp);
	if (!msh->env)
		return (1);
	msh_env_defaults(msh);
	return (0);
}
