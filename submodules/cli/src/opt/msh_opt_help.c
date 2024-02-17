/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_opt_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:15:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 04:52:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/cli/opt.h>

void	msh_print_version(t_minishell *msh, int fd);

void	msh_print_help(t_minishell *msh, int fd)
{
	const char	*argv0;

	argv0 = msh->launch_args.argv[0];
	ft_dprintf(fd, "Usage:  %s [GNU long option] [option] ...\n", argv0);
	ft_dprintf(fd, "        %s [GNU long option] [option] script-file ...\n",
		argv0);
	ft_dprintf(fd, "GNU long options:\n");
	ft_dprintf(fd, "        --help\n");
	ft_dprintf(fd, "        --version\n");
	ft_dprintf(fd, "Shell options:\n");
	ft_dprintf(fd, "        -c command         (invocation only)\n");
}

int	msh_opt_help(t_minishell *msh)
{
	msh_print_version(msh, 1);
	msh_print_help(msh, 1);
	return (0);
}
