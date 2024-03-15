/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_runner_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:06:09 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/10 03:20:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <msh/minishell.h>
#include <msh/io/path.h>

static bool	msh_check_binary_file(const char *sample, ssize_t sample_len)
{
	ssize_t			i;
	int				nline;
	unsigned char	c;

	if (sample_len >= 4 && sample[0] == 0x7f && sample[1] == 'E'
		&& sample[2] == 'L' && sample[3] == 'F')
		return (true);
	nline = 1;
	if (sample[0] == '#' && sample[1] == '!')
		nline = 2;
	i = 0;
	while (i < sample_len)
	{
		c = sample[i];
		if (c == '\n' && --nline == 0)
			return (false);
		if (c == '\0')
			return (true);
		i++;
	}
	return (false);
}

static int	msh_runner_check_binary(
	const char *file,
	char *string,
	ssize_t nread
) {
	int	ret;

	ret = 0;
	if (nread > 80)
		nread = 80;
	if (msh_check_binary_file(string, nread))
	{
		ft_dprintf(2, "%s: %s: cannot execute binary file\n", file, file);
		ret = 126;
	}
	free(string);
	return (ret);
}

static bool	msh_runner_check_meta(
	const char *file,
	int fd,
	struct stat *st,
	int *ret
) {
	size_t	file_size;
	char	*string;
	ssize_t	nread;

	file_size = (size_t) st->st_size;
	if ((off_t) file_size != st->st_size || file_size + 1 < file_size)
	{
		ft_dprintf(2, "%s: %s: file is too large\n", file, file);
		*ret = 126;
	}
	else
	{
		if (file_size > SSIZE_MAX)
			file_size = SSIZE_MAX;
		string = ft_calloc(file_size + 1, sizeof(char));
		if (string)
		{
			nread = read(fd, string, file_size);
			if (nread >= 0)
				string[nread] = 0;
			*ret = msh_runner_check_binary(file, string, nread);
		}
	}
	return (*ret == 0);
}

bool	msh_runner_check(t_minishell *msh, const char *file, int fd, int *ret)
{
	struct stat	st;

	if (fstat(fd, &st) < 0)
	{
		ft_dprintf(2, "%s: %s: %s\n", msh->name, file, strerror(errno));
		*ret = 1;
	}
	else if (S_ISDIR(st.st_mode))
	{
		ft_dprintf(2, "%s: %s: Is a directory\n", msh->name, file);
		*ret = 126;
	}
	else if (!S_ISREG(st.st_mode))
	{
		ft_dprintf(2, "%s: %s: not a regular file\n", msh->name, file);
		*ret = 126;
	}
	else
		msh_runner_check_meta(file, fd, &st, ret);
	return (*ret == 0);
}
