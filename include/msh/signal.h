/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:53:49 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/03 00:02:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <msh/defaults.h>
# include <signal.h>

extern int	g_sigval;

void	msh_signal_handler(int sigval);
void	msh_signal_init(void);

#endif // SIGNAL_H
