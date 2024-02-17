/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_opt_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:15:09 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 04:55:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>

int	msh_opt_command(t_minishell *msh)
{
	const char	*cmd;

	if (msh->launch_args.argc == 2)
	{
		ft_dprintf(2, "%s: -c: option requires an argument\n",
			msh->launch_args.argv[0]);
		return (2);
	}
	cmd = msh->launch_args.argv[2];
	if (msh->launch_args.argc > 3)
		msh->name = msh->launch_args.argv[3];
	ft_printf("cmd: %s\n", cmd);
	return (0);
}
