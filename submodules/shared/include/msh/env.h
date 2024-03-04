/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:38:10 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 20:27:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <msh/minishell.h>

void	msh_env_defaults(t_minishell *msh);
void	msh_env_free(t_minishell *msh);
void	msh_env_node_free(t_map_node *node);
char	*msh_env_get(t_minishell *msh, const char *key);
void	msh_env_populate(t_minishell *msh);
char	**msh_env_tab(t_minishell *msh);
void	msh_env_tab_free(char **tab);

#endif // ENV_H
