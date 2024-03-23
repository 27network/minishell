/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_registry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:05:17 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 16:54:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <msh/exec/builtin.h>

/**
 * @brief Get the registry of builtins
 *
 * This is the ONLY static "hack" in the project, which is necessary since we
 * access it on shared object construction and don't have shared resources 
 * with main() at that point.
 *
 * This was either that or putting a 64bit pointer as a string literal appended
 * to argv[0] so be happy this is here.
 *
 * @return t_list** The registry
 */
t_builtin	*msh_builtin_registry(void)
{
	static t_builtin	registry[BUILTIN_REGISTRY_SIZE];
	static bool			init = false;

	if (!init)
	{
		ft_memset(registry, 0, sizeof(registry));
		init = true;
	}
	return (registry);
}
