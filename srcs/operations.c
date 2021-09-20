/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:52:14 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 15:41:33 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**								# Operations #
**
**			Function that takes the stacks and a string which identifies which
**			operation to do on the stacks.
**
**			sa, sb and ss are swap operations. sa swaps the first two elements
**			of stackA, sb swaps the first two elements of stackB, and ss does
**			an sa and sb at the same time. It only works if there are two or
**			more elements on a stack.
**
**			pa and pb are push operations. pa pushes the first element of
**			stackB to the top of stackA, and pb pushes the first element of
**			stackA to the top of stackB.
**
**			ra, rb and rr are rotate operations. ra shifts up all elements of
**			stackA by 1 position, with the first element becoming the last. rb
**			shifts up all elements of stackB by 1 position, with the first 
**			element becoming the last. rr does ra and rb at the same time.
**
**			rra, rrb and rrr are reverse rotate operations. rra shifts down all
**			elements of stackA by 1 position, with the last element becoming
**			the first. rrb shifts down all elements of stackB by 1 position,
**			with the last element becoming the first. rrr does rra and rrb at
**			the same time.
*/

void	operations(t_stacks *stacks, char *op)
{
	if (ft_strcmp(op, "sa"))
		swap(stacks->stackA);
	else if (ft_strcmp(op, "sb"))
		swap(stacks->stackB);
	else if (ft_strcmp(op, "ss"))
	{
		swap(stacks->stackA);
		swap(stacks->stackB);
	}
	else if (ft_strcmp(op, "pa"))
		push(stacks->stackB, stacks->stackA, stacks->size);
	else if (ft_strcmp(op, "pb"))
		push(stacks->stackA, stacks->stackB, stacks->size);
	else if (ft_strcmp(op, "ra"))
		rotate(stacks->stackA, stacks->size);
	else if (ft_strcmp(op, "rb"))
		rotate(stacks->stackB, stacks->size);
	else if (ft_strcmp(op, "rr"))
	{
		rotate(stacks->stackA, stacks->size);
		rotate(stacks->stackB, stacks->size);
	}
	else if (ft_strcmp(op, "rra"))
		reverse_rotate(stacks->stackA, stacks->size);
	else if (ft_strcmp(op, "rrb"))
		reverse_rotate(stacks->stackB, stacks->size);
	else if (ft_strcmp(op, "rrr"))
	{
		reverse_rotate(stacks->stackA, stacks->size);
		reverse_rotate(stacks->stackB, stacks->size);
	}
	printf("%s\n", op);
}

void	swap(int **a)
{
	int	*temp;

	if (a[1] != NULL)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
}

void	push(int **a, int **b, int size)
{
	int	i;

	i = size - 1;
	if (a[0] != NULL)
	{
		while (i)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = a[0];
		i = 0;
		while (i < size - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = NULL;
	}
}

void	rotate(int **a, int size)
{
	int	i;
	int	f;
	int	*temp;

	i = 0;
	while (i < size && a[i])
		i++;
	temp = a[0];
	f = 0;
	while (f < i - 1)
	{
		a[f] = a[f + 1];
		f++;
	}
	a[f] = temp;
}

void	reverse_rotate(int **a, int size)
{
	int	i;
	int	f;
	int	*temp;

	i = 0;
	while (i < size && a[i])
		i++;
	temp = a[i - 1];
	f = i - 1;
	while (f)
	{
		a[f] = a[f - 1];
		f--;
	}
	a[0] = temp;
}
