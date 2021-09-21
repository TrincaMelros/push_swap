/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:18:06 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/21 14:27:47 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	garbage_collector(t_stacks *s, int f)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s->sta[i])
		{
			free(s->sta[i]);
			i++;
		}
		i = 0;
		while (s->stb[i])
		{
			free(s->stb[i]);
			i++;
		}
		free(s->sta);
		free(s->stb);
	}
	if (i == 1)
		exit(0);
}
