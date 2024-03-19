/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_register.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:04:42 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 23:13:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/exec/builtin.h>

void	msh_builtin_register(
	const char *name,
	int *(func),
	bool need_env,
	bool need_msh
) {
	t_builtin	*builtin;

	builtin = ft_calloc(1, sizeof(t_builtin));
	if (!builtin)
	{
		ft_dprintf(2, "builtin-reg: allocation failure for '%s', aborting.\n",
			name);
		exit(-1);
	}
	ft_lst_tadd(msh_builtin_registry(), builtin);
}
