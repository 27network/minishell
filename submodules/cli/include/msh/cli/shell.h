/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:19:05 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/24 05:23:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <msh/minishell.h>

void	msh_shell_loop(t_minishell *msh);

char	*msh_prompt_bash(t_minishell *msh);
int		msh_handle_line(t_minishell *msh, char *line);

#endif // SHELL_H
