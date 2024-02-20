/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:45:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 22:04:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>

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
	msh->name = argv[0];
	msh->launch_args.argc = argc;
	msh->launch_args.argv = (const char **)argv;
	msh->launch_args.envp = (const char **)envp;
	msh->env = ft_map_new(100, msh_string_hash,
			(t_map_cmp_function *) &ft_strcmp);
	msh->free_buffer = NULL;
	return (0);
}
