/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_run_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:41:40 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:55:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/path.h>

/**
 * TODO: add those checks: 
 * https://github.com/bminor/bash/blob/master/builtins/evalfile.c#L136-L190
 * (checkout 7d7979ba4c2b7848b81f526eac44340909ddd5a1)
 */
int	msh_run_file(t_minishell *msh, const char *filename)
{
	char	*resolved;

	resolved = msh_resolve_path(msh, filename);
	if (!resolved)
	{
		ft_dprintf(2, "%s: %s: %s\n", msh->name, filename, "No such file or "
			"directory");
		return (127);
	}
	msh->name = resolved;
	ft_dprintf(2, "%s: %s: %s\n", msh->name, resolved, "running files or "
		"scripts is not implemented yet");
	free(resolved);
	return (2);
}
