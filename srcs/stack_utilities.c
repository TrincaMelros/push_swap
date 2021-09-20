/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:26:24 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/21 00:21:37 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**								# Is Sorted #
**
**			This function simply takes a stack and checks if its sorted. I use
**			it right at the beginning of the program to make sure instructions
**			are actually needed. If it is sorted, the program ends right away.
*/

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = stacks->size - 1;
	while (i)
	{
		if (*(stacks->sta)[i] > *(stacks->sta)[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}

/*
**								# Start Stack #
**
**			This function is used to start stackB, which is filled with null
**			pointers.
*/

void	start_stack(int **a, int i)
{
	while (i)
	{
		a[i - 1] = NULL;
		i--;
	}
}

/*
**								# Add Stack #
**
**			Receives an int and returns it as a pointer. Useful to add args
**			to a stack, which is an array of pointers.
*/

void	*add_stack(int i)
{
	int	*x;

	x = malloc(sizeof(int *));
	*x = i;
	return (x);
}

/*
**								# Stack Printer #
**
**			Receives the stacks and prints them in a nice visualizing format
*/

void	stack_printer(t_stacks stacks)
{
	int	j;

	j = 0;
	while (j < stacks.size)
	{
		if (stacks.sta[j] != NULL && stacks.stb[j] == NULL)
			printf("%d __ N\n", *(stacks.sta)[j]);
		else if (stacks.sta[j] == NULL && stacks.stb[j] != NULL)
			printf("N __ %d\n", *(stacks.stb)[j]);
		else if (stacks.sta[j] == NULL && stacks.stb[j] == NULL)
			printf("N __ N\n");
		else
			printf("%d __ %d\n", *(stacks.sta)[j], *(stacks.stb)[j]);
		j++;
	}
	printf("\nA __ B\n");
}

/*
**								# Initialize Stacks #
**
**			This functions receives the empty stacks structure and initializes
**			its contents. It also calls on start_stack to fill stackB with
**			null pointers.
*/

void	init_stacks(t_stacks *stacks, int i)
{
	stacks->sta = malloc(sizeof(int *) * i);
	stacks->stb = malloc(sizeof(int *) * i);
	stacks->size = i;
	start_stack(stacks->stb, i);
}
