/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:55:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:41:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTS_H
# define DEFAULTS_H

# include <msh/minishell.h>

enum e_builtin_need
{
	NEED_ENV = 0b01,
	NEED_MSH = 0b10,
};

typedef struct s_builtin
{
	const char	*name;

	int			(*func)();
	int			need;

}	t_builtin;

void		msh_builtin_register(t_builtin builtin);

#endif // DEFAULTS_H
