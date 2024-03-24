/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:56:48 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/24 16:03:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/features.h>
#if FEAT_BUILTIN_COLON
# include <msh/builtin/defaults.h>

/**
 * @brief no-op
 */
int	msh_builtin_colon(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}

__attribute__((constructor))
void	register_colon(void)
{
	msh_builtin_register((t_builtin){
		.name = ":",
		.func = msh_builtin_colon,
	});
}
#endif // FEAT_BUILTIN_COLON
