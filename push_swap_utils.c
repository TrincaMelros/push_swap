/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:26:24 by malmeida          #+#    #+#             */
/*   Updated: 2021/05/26 12:56:30 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			printf("%d __ N\n", *a[j]);
		else if (a[j] == NULL && b[j] != NULL)
			printf("N __ %d\n", *b[j]);
		else if (a[j] == NULL && b[j] == NULL)
			printf("N __ N\n");
		else
			printf("%d __ %d\n", *a[j], *b[j]);
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

int		ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32)))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	number = 0;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		number *= 10;
		number =+ nptr[i] - '0';
		i++;
	}
	return (number * sign);
}
