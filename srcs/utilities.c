/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:10:15 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 23:36:39 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**								# Operations #
**
**			Function that takes the stacks and a string which identifies which
**			operation to do on the stacks. It is split in two because of the 
**			25 line limit per function we have at 42. The first function
**			carries the swap and push functions, while the second features the
**			reverse functions.
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

void	operations1(t_stacks *stacks, char *op)
{
	if (ft_strcmp(op, "sa"))
		swap(stacks->sta);
	else if (ft_strcmp(op, "sb"))
		swap(stacks->stb);
	else if (ft_strcmp(op, "ss"))
	{
		swap(stacks->sta);
		swap(stacks->stb);
	}
	else if (ft_strcmp(op, "pa"))
		push(stacks->stb, stacks->sta, stacks->size);
	else if (ft_strcmp(op, "pb"))
		push(stacks->sta, stacks->stb, stacks->size);
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
}

void	operations2(t_stacks *stacks, char *op)
{
	if (ft_strcmp(op, "ra"))
		rotate(stacks->sta, stacks->size);
	else if (ft_strcmp(op, "rb"))
		rotate(stacks->stb, stacks->size);
	else if (ft_strcmp(op, "rr"))
	{
		rotate(stacks->sta, stacks->size);
		rotate(stacks->stb, stacks->size);
	}
	else if (ft_strcmp(op, "rra"))
		reverse_rotate(stacks->sta, stacks->size);
	else if (ft_strcmp(op, "rrb"))
		reverse_rotate(stacks->stb, stacks->size);
	else if (ft_strcmp(op, "rrr"))
	{
		reverse_rotate(stacks->sta, stacks->size);
		reverse_rotate(stacks->stb, stacks->size);
	}
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
}

/*
**								# Is Duplicate #
**
**			This function receives an array with the arguments and checks
**			for any duplicates. It's part of the argument parsing.
**
*/

void	is_duplicate(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				ft_putstr_fd("Error\n", 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

/*
**								# Is Valid #
**
**			This function checks if the argument is a number, checking
**			as well for double + or - signs.
*/

int	is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] == '-')
				return (0);
			i++;
		}
		if (s[i] > '9' || s[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

/*
**								# String Compare #
**
**			Simple function that compares two strings, returning 1 if they are
**			the same, and 0 if they are different. It's used by this program to 
**			figure out which operation needs to be used.
*/

int	ft_strcmp(char *s1, char *s2)
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
