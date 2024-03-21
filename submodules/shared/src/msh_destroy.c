/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:55:20 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/21 22:31:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/env.h>

void	msh_destroy(t_minishell *msh)
{
	if (!msh)
	{
		ft_putendl_fd(STDERR_FILENO, "msh_destroy: msh is NULL");
		exit(-1);
	}
	msh_env_free(msh);
	if (msh->free_buffer)
		ft_lst_free(&msh->free_buffer, free);
}
