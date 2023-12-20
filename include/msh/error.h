/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:49:01 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 08:02:46 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdbool.h>

typedef enum e_msh_serror
{
	MSH_OK = 0,
	MSH_ERROR,
	MSH_MALLOC,
	MSH_SYNTAX,
	MSH_UNEXPECTED_TOKEN,
	MSH_NOT_FOUND,
	MSH_NOT_VALID_IDENTIFIER,
	MSH_NOT_IMPLEMENTED
}	t_msh_serror;

typedef struct s_msh_error
{
	t_msh_serror		error_type;
	char				*message;
	void				*extra;
}	t_msh_error;

t_msh_error	*msh_error(t_msh_serror error_type, char *message, void *extra);
bool		msh_errored(t_msh_error *error, bool print);

#endif // ERROR_H
