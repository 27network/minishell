/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 02:25:14 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 03:15:34 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include <msh/minishell.h>

/**
 * @brief Resolve the path of a file or script
 *
 * @implementation	This function will first try a relative path, then an
 * 					absolute path, and finally search the PATH environment
 * 					variable for the file. If the file is not found, it will
 * 					return NULL.
 *
 * @param msh		The minishell instance
 * @param filename	The name of the file or script
 *
 * @return			The resolved path of the file or script, or NULL if not found
 */
char	*msh_resolve_path(t_minishell *msh, const char *filename);

#endif // PATH_H
