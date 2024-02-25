/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:55:20 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 22:45:59 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/env.h>

void	msh_destroy(t_minishell *msh)
{
	msh_env_free(msh);
	ft_lst_free(&msh->free_buffer, free);
}
