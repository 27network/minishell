/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:55:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/21 22:34:00 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTS_H
# define DEFAULTS_H

# include <msh/minishell.h>

# define NEEDS_ENV 0b01
# define NEEDS_MSH 0b10

typedef struct s_builtin
{
	const char	*name;

	int			(*func)();
	int			needs;
}	t_builtin;

void		msh_builtin_register(t_builtin builtin);

#endif // DEFAULTS_H
