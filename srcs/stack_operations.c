/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:37:00 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:18:38 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**						# Stack Operations #
**
**			The swap function takes a stack and swaps its first two elements.
**
**			The push function takes two stacks and its maximum size. it then
**			pushes the first element from stack **a and places it up top of
**			stack **b.
**
**			The rotate function takes a stack and shifts all of its elements up
**			by 1. The first element becomes the last of the stack.
**
**			The reverse rotate function takes a stack and shifts all of its
**			elements down by 1. The last element becomes the first of the stack
*/

void	swap(int **a)
{
	int	temp;

	if ((*a)[1] != -1)
	{
		temp = (*a)[0];
		(*a)[0] = (*a)[1];
		(*a)[1] = temp;
	}
}

void	push(int **a, int **b, int size)
{
	int	i;

	i = size - 1;
	if ((*a)[0] != -1)
	{
		while (i)
		{
			(*b)[i] = (*b)[i - 1];
			i--;
		}
		(*b)[0] = (*a)[0];
		i = 0;
		while (i < size - 1)
		{
			(*a)[i] = (*a)[i + 1];
			i++;
		}
		(*a)[i] = -1;
	}
}

void	rotate(int **a, int size)
{
	int	i;
	int	f;
	int	temp;

	i = 0;
	while (i < size && (*a)[i] != -1)
		i++;
	temp = (*a)[0];
	f = 0;
	while (f < i - 1)
	{
		(*a)[f] = (*a)[f + 1];
		f++;
	}
	(*a)[f] = temp;
}

void	reverse_rotate(int **a, int size)
{
	int	i;
	int	f;
	int	temp;

	i = 0;
	while (i < size && (*a)[i] != -1)
		i++;
	temp = (*a)[i - 1];
	f = i - 1;
	while (f)
	{
		(*a)[f] = (*a)[f - 1];
		f--;
	}
	(*a)[0] = temp;
}
