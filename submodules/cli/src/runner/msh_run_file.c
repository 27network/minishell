/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_run_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:41:40 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/10 00:12:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/path.h>

static int	msh_resolve_fd(t_minishell *msh, const char *filename, char **name)
{
	int		fd;
	char	*resolved;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		resolved = msh_resolve_path(msh, filename);
		if (resolved)
		{
			fd = open(resolved, O_RDONLY);
			if (fd >= 0)
				*name = resolved;
			else
				free(resolved);
		}
	}
	else
		*name = ft_strdup((char *)filename);
	return (fd);
}

/**
 * TODO: add those checks: 
 * https://github.com/bminor/bash/blob/master/builtins/evalfile.c#L136-L190
 * (checkout 7d7979ba4c2b7848b81f526eac44340909ddd5a1)
 */
void	msh_run_file(t_minishell *msh, const char *filename)
{
	char		*resolved;
	int			fd;
	struct stat	finfo;

	msh->name = NULL;
	fd = msh_resolve_fd(msh, filename, &msh->name);
	if (fd < 0 || fstat(fd, &finfo) < 0)
	{
		if (fd >= 0)
			close(fd);
		if (msh->name)
			free(msh->name);
		ft_dprintf(2, "%s: %s: %m\n", msh->name, filename);
		exit(126);
	}
	if (S_ISDIR(finfo.st_mode))
	{
		ft_dprintf(2, "%s: %s: %s\n", msh->name, filename, strerror(EISDIR));
		exit(126);
	}
	if (!S_ISREG(finfo.st_mode))
	{
		ft_dprintf(2, "%s: %s: %s\n", msh->name, filename, strerror(EINVAL));
		exit(126);
	}
	free(msh->name);
	exit(0);
}
