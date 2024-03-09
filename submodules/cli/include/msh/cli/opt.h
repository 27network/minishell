/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:15:43 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/07 04:02:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H

# include <msh/minishell.h>

# define RETURN_SUCCESS 0
# define RETURN_INVALID_OPT 2

void	msh_handle_opts(t_minishell *msh);

# ifdef MSH_OPT_IMPL

void	msh_opt_command(t_minishell *msh);
void	msh_opt_help(t_minishell *msh);
void	msh_opt_version(void);

# endif // MSH_OPT_IMPL

#endif // OPT_H
