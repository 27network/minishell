/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_opt_version.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:03:09 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 04:51:10 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/cli/opt.h>

void	msh_print_version(t_minishell *msh, int fd)
{
	ft_dprintf(fd, "%s, version %s\n", msh->name, MSH_VERSION);
}

int	msh_opt_version(t_minishell *msh)
{
	msh_print_version(msh, 1);
	ft_printf("Copyright (C) 2024 Seekrs\n");
	ft_printf("License MIT: <https://opensource.org/licenses/MIT>\n\n");
	ft_printf("This is free software; you are free to change and "
		"redistribute it.\n");
	ft_printf("There is NO WARRANTY, to the extent permitted by law.\n");
	return (0);
}
