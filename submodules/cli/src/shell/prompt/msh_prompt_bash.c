/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt_bash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:10:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 10:32:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/minishell.h>
#include <msh/io/system.h>

char	*msh_prompt_bash(void)
{
	char	*user;
	char	*home;
	char	*cwd;
	char	*format;
	char	sep;

	user = getenv("USER");
	home = getenv("HOME");
	if (!user || !home)
		return (ft_strdup(MSH_DEFAULT_NAME"-"MSH_VERSION"$ "));
	sep = '$';
	if (ft_strncmp(user, "root", 5) == 0)
		sep = '#';
	cwd = getcwd(NULL, 0);
	if (!cwd)
		cwd = ft_strdup("?");
	if (ft_strchr(cwd, '/'))
		format = ft_format("[%s@%s %s]%c ", user, msh_get_hostname(),
				ft_strrchr(cwd, '/') + 1, sep);
	else
		format = ft_format("[%s@%s %s]%c ", user, msh_get_hostname(), cwd, sep);
	free(cwd);
	return (format);
}
