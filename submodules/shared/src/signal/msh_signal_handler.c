/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:13:10 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 22:23:44 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <msh/signal.h>

int	g_signal;

void	msh_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_signal = signo;
}
