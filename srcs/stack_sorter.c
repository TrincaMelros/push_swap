/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:00:56 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:22:50 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**						# Stack Solver #
**
**			This is the main function of the solving part of the program.
**			Depending on the amount of arguments, it calls different functions
**			to solve and order the stack. The main sorting method is
**			radix_sort, but it doesn't work great for small numbers of args,
**			so I included different methods for these cases.
*/

void	stack_sorter(t_stacks *s)
{
	if (s->size == 2)
		operations1(s, "sa");
	else if (s->size == 3)
		three_sorter(s);
	else if (s->size == 4)
		four_sorter(s);
	else if (s->size == 5)
		five_sorter(s);
	else
		radix_sort(s);
}

/*
**						# Three Sorter #
**
**			As the name implies, this function works at solving cases where
**			there are three arguments in stackA. This method relies on there
**			only being 5 different combinations of orders of 3 numbers in a
**			stack. There are 6, actually, but the 6th case that is not
**			represented is an already sorted stack.
*/

void	three_sorter(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2])
	{
		if (s->a[0] > s->a[2])
			operations2(s, "ra");
		else
			operations1(s, "sa");
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2])
	{
		if (s->a[0] > s->a[2])
			operations2(s, "rra");
		else
		{
			operations1(s, "sa");
			operations2(s, "ra");
		}
	}
	else
	{
		operations1(s, "sa");
		operations2(s, "rra");
	}
}

/*
**						# Four Sorter #
**
**			Four sorter works in a very similar way to three sorter, but with
**			an extra twist. It will look for the lowest number, and push it
**			to stackB. It will then use the three sorter method to sort stackA,
**			and then push the lowest number back to stackA.
*/

void	four_sorter(t_stacks *s)
{
	while (s->a[0] != 0)
		operations2(s, "ra");
	operations1(s, "pb");
	three_sorter(s);
	operations1(s, "pa");
}

/*
**						# Five Sorter #
**
**			This function works very similarly to the previous function,
**			Four sorter, but instead of pushing the lowest number to stackB,
**			it pushes the 2 lowest numbers.
*/

void	five_sorter(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while (s->a[0] != 0 && s->a[0] != 1)
			operations2(s, "ra");
		operations1(s, "pb");
		i++;
	}
	three_sorter(s);
	if (s->b[0] == 0)
		operations1(s, "sb");
	operations1(s, "pa");
	operations2(s, "pa");
}

/*
**						# Radix Sort #
**
**			This is the main algorithm for sorting the stack this program uses.
**			It works by using bitwise and bitshift operators to compare the
**			numbers and sort them. It is usually used with decimal numbers, but
**			since we only have two stacks, the bit operators come into use as
**			think of the args in binary.
**
**			The algorithm compares the numbers bit by bit, pushing them onto stackB
**			if the bit is 0, and sending them to the bottom of stackA if the bit is
**			1. The stacks are then combined by using pa, and the process is repeated
**			for every bit.
*/

void	radix_sort(t_stacks *s)
{
	int	num;
	int	max_bits;
	int	i;
	int	f;

	max_bits = 0;
	while ((s->size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		f = 0;
		while (f < s->size)
		{
			num = s->a[0];
			if (((num >> i) & 1) == 1)
				operations2(s, "ra");
			else
				operations1(s, "pb");
			f++;
		}
		while ((s->b[0]) != -1)
			operations1(s, "pa");
		i++;
	}
}
