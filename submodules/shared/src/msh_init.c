/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:45:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/21 22:33:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/system.h>
#include <msh/env.h>

/**
 * @brief A simple hash function for strings.
 *
 * @param data The string to hash.
 * @return uint64_t The hash value.
 */
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

void	msh_init(
	t_minishell *msh,
	int argc,
	const char **argv,
	const char **envp
) {
	(void) argc;
	ft_bzero(msh, sizeof(t_minishell));
	msh->name = argv[0];
	msh->interactive = msh_is_interactive();
	msh->env = ft_map_new(100, msh_string_hash,
			(t_map_cmp_function *) &ft_strcmp);
	if (!msh->env)
	{
		ft_putendl_fd(STDERR_FILENO, "msh_init: failed to allocate env map");
		msh_exit(msh, -1);
	}
	if (!msh_env_populate(msh, envp))
	{
		ft_putendl_fd(STDERR_FILENO, "msh_init: failed to populate env");
		msh_exit(msh, -2);
	}
	msh_env_defaults(msh);
}
