/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:09:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 22:51:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H
# undef SIGNAL_H
# ifndef __MSH_SIGNAL_H__
#  define __MSH_SIGNAL_H__

#  if !defined(NSIG) && !defined(__USE_MISC)
#   define __USE_POSIX19930
#   define __USE_MISC
#  endif
#  include <signal.h>
#  include <msh/minishell.h>

extern int	g_signal;

/**
 * @brief Initializes default signal handling for minishell.
 *
 * @param msh The minishell instance. 
 */
void	msh_signal_init(t_minishell *msh);
void	msh_signal_handler(int signum);
void	msh_signal_setdfl(void);

# endif // __MSH_SIGNAL_H__
#endif // SIGNAL_H
