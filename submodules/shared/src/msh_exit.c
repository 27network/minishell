/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:59:42 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 22:07:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <stdlib.h>

void	msh_exit(t_minishell *msh, int64_t exit_code)
{
	msh_destroy(msh);
	exit(exit_code);
}
