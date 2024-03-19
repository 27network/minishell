/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:09:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 22:21:02 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <msh/externs.h>

extern int	g_signal;

void	msh_signal_init(void);
void	msh_signal_handler(int signum);
void	msh_signal_setdfl(void);

#endif // SIGNAL_H
