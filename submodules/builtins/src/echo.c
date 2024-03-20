/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:54:45 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:42:28 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/builtin/defaults.h>
#include <stdio.h>

static int	msh_builtin_echo(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("je echo mr.\n");
	return (0);
}

__attribute__((constructor))
void	register_echo(void)
{
	msh_builtin_register((t_builtin){
		.name = "echo",
		.func = msh_builtin_echo,
	});
}
