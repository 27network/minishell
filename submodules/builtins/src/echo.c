/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:54:45 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 03:36:31 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/builtin/default.h>
#include <stdio.h>

static int	echo$main(int argc, char **argv)
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
		.func = echo$main,
	});
}
