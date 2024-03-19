/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal_setdfl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:49:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/19 23:07:44 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh/signal.h>

void	msh_signal_setdfl(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		signal(i, SIG_DFL);
		i++;
	}
}
