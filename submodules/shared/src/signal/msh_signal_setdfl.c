/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal_setdfl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:49:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/22 22:46:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/signal.h>

void	msh_signal_setdfl(void)
{
	int	i;

	i = 0;
	while (i < _NSIG)
	{
		signal(i, SIG_DFL);
		i++;
	}
}
