/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:51:03 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 22:26:26 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**								# Stack Solver #
**
**			This is the main function of the solving part of the program.
**			Depending on the amount of arguments, it calls different functions
**			to solve and order the stack. The main sorting method is
**			radix_sort, but it doesn't work great for small numbers of args,
**			so I included different methods for these cases.
*/

void	stack_solver(t_stacks *stacks)
{
	if (stacks->size == 2)
		operations1(stacks, "sa");
	else if (stacks->size == 3)
		three_sorter(stacks);
	else if (stacks->size > 5)
		radix_sort(stacks);
}

/*
**								# Three Sorter #
**
**			As the name implies, this function works at solving cases where
**			there are three arguments in stackA. This method relies on there
**			only being 5 different combinations of orders of 3 numbers in a
**			stack. There are 6, actually, but the 6th case that is not
**			represented is an already sorted stack.
*/

void	three_sorter(t_stacks *stacks)
{
	if (*(stacks->sta)[0] > *(stacks->sta)[1] && \
			*(stacks->sta)[1] < *(stacks->sta)[2])
	{
		if (*(stacks->sta)[0] > *(stacks->sta)[2])
			operations2(stacks, "ra");
		else
			operations1(stacks, "sa");
	}
	else if (*(stacks->sta)[0] < *(stacks->sta)[1] && \
			*(stacks->sta)[1] > *(stacks->sta)[2])
	{
		if (*(stacks->sta)[0] > *(stacks->sta)[2])
			operations2(stacks, "rra");
		else
		{
			operations1(stacks, "sa");
			operations2(stacks, "ra");
		}
	}
	else
	{
		operations1(stacks, "sa");
		operations2(stacks, "rra");
	}
}

/*
**								# Radix Sort #
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

void	radix_sort(t_stacks *stacks)
{
	int	num;
	int	max_bits;
	int	i;
	int	f;

	max_bits = 0;
	while ((stacks->size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		f = 0;
		while (f < stacks->size)
		{
			num = *(stacks->sta)[0];
			if (((num >> i) & 1) == 1)
				operations2(stacks, "ra");
			else
				operations1(stacks, "pb");
			f++;
		}
		while ((stacks->stb[0]) != NULL)
			operations1(stacks, "pa");
		i++;
	}
}
