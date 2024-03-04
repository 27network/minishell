/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_handle_opts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:14:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 20:40:45 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Note: This argument handler doesn't support toggle flags.
 */
#define AVAILABLE_SHORT_OPTS "c"

#include <msh/cli/runner.h>
#define MSH_OPT_IMPL
#include <msh/cli/opt.h>

void	msh_print_help(t_minishell *msh, int fd);

static void	msh_handle_invalid(t_minishell *msh, const char *flag, bool is_long)
{
	if (is_long)
		ft_dprintf(2, "%s: %s: %s\n", msh->name, flag, "invalid option");
	else
		ft_dprintf(2, "%s: -%c: %s\n", msh->name, flag[0], "invalid option");
	msh_print_help(msh, 2);
}

static int	msh_handle_short(t_minishell *msh, const char *cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
	{
		if (!ft_strchr(AVAILABLE_SHORT_OPTS, cmds[i]))
		{
			msh_handle_invalid(msh, &cmds[i], false);
			return (2);
		}
		i++;
	}
	i = 0;
	while (cmds[i])
	{
		if (cmds[i] == 'c')
			return (msh_opt_command(msh));
		i++;
	}
	return (0);
}

static int	msh_handle_opt(t_minishell *msh, const char *cmd)
{
	if (ft_strncmp(cmd, "--", 2) == 0)
	{
		if (ft_strncmp(cmd, "--help", 7) == 0)
			return (msh_opt_help(msh));
		else if (ft_strncmp(cmd, "--version", 10) == 0)
			return (msh_opt_version());
		else
		{
			msh_handle_invalid(msh, cmd, true);
			return (2);
		}
	}
	else if (ft_strncmp(cmd, "-", 1) == 0)
		return (msh_handle_short(msh, cmd + 1));
	else
		return (msh_run_file(msh, cmd));
	return (0);
}

int	msh_handle_opts(t_minishell *msh)
{
	return (msh_handle_opt(msh, msh->launch_args.argv[1]));
}
