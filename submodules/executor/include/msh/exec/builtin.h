/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:50:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:41:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <msh/builtin/defaults.h>
# define BUILTIN_REGISTRY_SIZE 32

t_builtin	*msh_builtin_registry(void);
t_builtin	*msh_builtin_get(const char *name);

#endif // BUILTIN_H
