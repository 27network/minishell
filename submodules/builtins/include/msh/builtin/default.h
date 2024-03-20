/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:55:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:02:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_H
# define DEFAULT_H

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

#endif // DEFAULT_H
