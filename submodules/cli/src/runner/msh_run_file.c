/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_run_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:41:40 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:01:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/path.h>

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
	//TODO: add those checks: https://github.com/bminor/bash/blob/f3b6bd19457e260b65d11f2712ec3da56cef463f/builtins/evalfile.c#L136-L190
	ft_dprintf(2, "%s: %s: %s\n", msh->name, resolved, "running files or "
		"scripts is not implemented yet");
	free(resolved);
	return (2);
}
