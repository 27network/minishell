/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:46:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/17 05:04:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include <msh/minishell.h>

# ifdef MSH_CLI_UTILS

int		msh_fileno(FILE	*stream);
bool	msh_is_interactive(void);

# endif // MSH_CLI_UTILS

#endif // CLI_H
