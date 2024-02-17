/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_interactive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:02:54 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:04:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MSH_CLI_UTILS
#include <msh/cli/cli.h>

bool	msh_is_interactive(void)
{
	int	tty;

	tty = STDIN_FILENO;
	if (rl_instream)
		tty = msh_fileno(rl_instream);
	return (isatty(tty));
}
