/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 17:52:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# undef FLAGS_H
# ifndef __MSH_FLAGS_H__
#  define __MSH_FLAGS_H__

#  include <stdbool.h>

typedef struct s_msh_flags
{
	bool	print_ast;
	bool	print_pipelines;
	bool	print_tokens;
}	t_msh_flags;

# endif // __MSH_FLAGS_H__
#endif // FLAGS_H
