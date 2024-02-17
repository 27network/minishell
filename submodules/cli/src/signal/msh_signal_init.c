/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:10:08 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:13:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/externs.h>
#include <msh/cli/signal.h>

void	msh_signal_init(void)
{
	signal(SIGINT, msh_signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
