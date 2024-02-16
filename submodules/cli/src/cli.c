/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:46:03 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/16 17:17:44 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/cli/cli.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argv;
	if (argc == 1)
	{
		printf("prompt mode\n");
	}
	else
	{
		printf("arg parsing baby\n");
	}
	return (0);
}
