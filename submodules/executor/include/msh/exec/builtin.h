/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:50:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 17:47:46 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# undef BUILTIN_H
# ifndef __MSH_EXEC_BUILTIN_H__
#  define __MSH_EXEC_BUILTIN_H__

#  include <msh/builtin/defaults.h>
#  define BUILTIN_REGISTRY_SIZE 32

t_builtin	*msh_builtin_registry(void);
t_builtin	*msh_builtin_get(const char *name);

# endif // __MSH_EXEC_BUILTIN_H__
#endif // BUILTIN_H
