/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:54:45 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/19 23:02:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>

static int	main(int argc, char **argv)
{
	printf("je echo mr.\n");
	return (0);
}

__attribute__((constructor))
void	register_echo(void)
{
	msh_builtin_register("echo", &main, false, false);
}
