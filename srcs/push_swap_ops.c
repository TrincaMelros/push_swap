/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:52:14 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/19 12:02:34 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	operations(int **stackA, int **stackB, int i, char *op)
{
	if (ft_strcmp(op, "sa"))
		swap(stackA);
	else if (ft_strcmp(op, "sb"))
		swap(stackB);
	else if (ft_strcmp(op, "ss"))
	{
		swap(stackA);
		swap(stackB);
	}
	else if (ft_strcmp(op, "pa"))
		push(stackB, stackA, i);
	else if (ft_strcmp(op, "pb"))
		push(stackA, stackB, i);
	else if (ft_strcmp(op, "ra"))
		rotate(stackA, i);
	else if (ft_strcmp(op, "rb"))
		rotate(stackB, i);
	else if (ft_strcmp(op, "rr"))
	{
		rotate(stackA, i);
		rotate(stackB, i);
	}
	else if (ft_strcmp(op, "rra"))
		reverse_rotate(stackA, i);
	else if (ft_strcmp(op, "rrb"))
		reverse_rotate(stackB, i);
	else if (ft_strcmp(op, "rrr"))
	{
		reverse_rotate(stackA, i);
		reverse_rotate(stackB, i);
	}
	printf("\n%s\n", op);
}

void	swap(int **a)
{
	int	*temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	push(int **a, int **b, int i)
{
	int	f;

	f = i;
	if (b[0] != NULL)
	{
		while (i - 2 >= 0)
		{
			a[i - 1] = a[i - 2];
			i--;
		}
		a[0] = b[0];
		i = 0;
		while (i < f - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[i] = NULL;
	}
}

void	rotate(int **a, int i)
{
	int	f;
	int	j;
	int	*temp;

	j = 0;
	while (a[j])
		j++;
	temp = a[0];
	f = 0;
	while (j > 1)
	{
		a[f] = a[f + 1];
		f++;
		j--;
	}
	a[f] = temp;
}

void	reverse_rotate(int **a, int i)
{
	int	*temp;
	int	j;

	j = 0;
	while (a[j])
		j++;
	j--;
	temp = a[j];
	while (j > 0)
	{
		a[j] = a[j - 1];
		j--;
	}
	a[0] = temp;
}
