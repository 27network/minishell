/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:15:43 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 02:16:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H

# include <msh/minishell.h>

int	msh_handle_opts(t_minishell *msh);

# ifdef MSH_OPT_IMPL

int	msh_opt_command(t_minishell *msh);
int	msh_opt_help(t_minishell *msh);
int	msh_opt_version(t_minishell *msh);

# endif // MSH_OPT_IMPL

#endif // OPT_H
