/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:15:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 23:18:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/exec/builtin.h>

static void	msh_builtin_print(t_builtin *builtin)
{
	ft_printf("%s ", builtin->name);
}

void	msh_builtin_init(t_minishell *msh)
{
	t_list	*registry;

	registry = *msh_builtin_registry();
	ft_printf("loaded %d builtins:\n" );
	ft_lst_for_each(*msh_builtin_registry(), &msh_builtin_print);
}
