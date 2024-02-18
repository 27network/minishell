/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:46:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/18 23:41:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# define TEST wow

# include <msh/minishell.h>

# ifdef MSH_CLI_UTILS

int		msh_fileno(FILE	*stream);
bool	msh_is_interactive(void);

# endif // MSH_CLI_UTILS

#endif // CLI_H
