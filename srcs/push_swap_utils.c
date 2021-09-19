/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:26:24 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/19 11:40:04 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	start_stack(int **a, int i)
{
	while (i)
	{
		a[i - 1] = NULL;
		i--;
	}
}

void	*add_stack(int i)
{
	int	*x;

	x = malloc(sizeof(int *));
	*x = i;
	return (x);
}

void	stack_printer(int **a, int **b, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (a[j] != NULL && b[j] == NULL)
			printf("%d __ N\n", (*a)[j]);
		else if (a[j] == NULL && b[j] != NULL)
			printf("N __ %d\n", (*b)[j]);
		else if (a[j] == NULL && b[j] == NULL)
			printf("N __ N\n");
		else
			printf("%d __ %d\n", (*a)[j], (*b)[j]);
		j++;
	}
	printf("\nA __ B\n");
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	else
		return (0);
}
