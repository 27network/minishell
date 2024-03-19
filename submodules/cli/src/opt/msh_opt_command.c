/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_opt_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:15:09 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 22:48:16 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/cli/shell.h>
#include <msh/exec/exec.h>

static int	msh_find_flag_index(const char **argv)
{
	int		i;
	size_t	length;

	i = 0;
	while (argv[i])
	{
		length = ft_strlen(argv[i]);
		if (argv[i][0] == '-' && argv[i][length - 1] == 'c')
			return (i);
		i++;
	}
	return (-1);
}

void	msh_opt_command(t_minishell *msh)
{
	const char	*cmd;
	int			c_flag_index;

	c_flag_index = msh_find_flag_index(msh->launch_args.argv);
	if (c_flag_index == -1 || msh->launch_args.argc <= c_flag_index + 1)
	{
		ft_dprintf(2, "%s: -c: option requires an argument\n",
			msh->launch_args.argv[0]);
		msh_destroy(msh);
		exit(2);
	}
	cmd = msh->launch_args.argv[c_flag_index + 1];
	if (msh->launch_args.argc > c_flag_index + 2)
		msh->name = msh->launch_args.argv[c_flag_index + 2];
	if (msh->name == NULL)
		msh->name = MSH_DEFAULT_NAME;
	msh->exit_code = msh_handle_line(msh, (char *) cmd);
	msh_destroy(msh);
	exit(msh->exit_code);
}
