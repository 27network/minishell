/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_register.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:04:42 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 00:21:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/exec/builtin.h>

void	msh_builtin_register(t_builtin builtin)
{
	t_builtin	*builtins;
	size_t		i;

	builtins = msh_builtin_registry();
	i = 0;
	while (i < BUILTIN_REGISTRY_SIZE)
	{
		if (!builtins[i].name)
		{
			builtins[i] = builtin;
			return ;
		}
		i++;
	}
	ft_dprintf(2, "builtin registry: too many builtins registered, "
		"max is %d\n", BUILTIN_REGISTRY_SIZE);
	exit(-1);
}
