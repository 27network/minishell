/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:50:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 23:18:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <msh/minishell.h>

typedef struct s_builtin
{
	const char	*name;

	int			(*func)(int argc, char **argv);
	int			(*func_env)(int argc, char **argv, char **envp);
	int			(*func_msh)(int argc, char **argv, t_minishell *msh);
	int			(*func_env_msh)(int argc, char **argv, char **envp,
			t_minishell *msh);
}	t_builtin;

void		msh_builtin_register(const char *name, int (*func),
				bool need_env, bool need_msh);
t_list		**msh_builtin_registry(void);
void		msh_builtin_init(t_minishell *msh);

t_builtin	*msh_get_builtin(

#endif // BUILTIN_H
