/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_run_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:06:45 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/15 20:35:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>

int	msh_run_script(t_minishell *msh, int fd, const char *filename)
{
	printf("%s: %s: running scripts isn't supported.\n", msh->name, filename);
	(void)fd;
	return (121);
}
