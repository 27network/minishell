/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:10:08 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 21:12:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/signal.h>

void	msh_signal_init(t_minishell *msh)
{
	(void) msh;
	signal(SIGINT, msh_signal_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
