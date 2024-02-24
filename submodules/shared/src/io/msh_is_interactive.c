/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_interactive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:02:54 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 05:20:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/io/system.h>
#include <msh/externs.h>

bool	msh_is_interactive(void)
{
	int	tty;

	tty = STDIN_FILENO;
	if (rl_instream)
		tty = msh_fileno(rl_instream);
	return (isatty(tty));
}
