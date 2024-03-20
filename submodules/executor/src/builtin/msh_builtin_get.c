/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:38:27 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:37:08 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/exec/builtin.h>

t_builtin	*msh_builtin_get(const char *name)
{
	size_t		i;
	t_builtin	*g_builtin;

	i = 0;
	g_builtin = msh_builtin_registry();
	if (!g_builtin || !g_builtin[0].name)
		return (NULL);
	while (i < BUILTIN_REGISTRY_SIZE && g_builtin[i].name)
	{
		if (ft_strcmp(name, g_builtin[i].name) == 0)
			return (&g_builtin[i]);
		i++;
	}
	return (NULL);
}
