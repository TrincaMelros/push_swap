/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:26:24 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 15:58:14 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if (stacks.stackA[j] != NULL && stacks.stackB[j] == NULL)
			printf("%d __ N\n", *(stacks.stackA)[j]);
		else if (stacks.stackA[j] == NULL && stacks.stackB[j] != NULL)
			printf("N __ %d\n", *(stacks.stackB)[j]);
		else if (stacks.stackA[j] == NULL && stacks.stackB[j] == NULL)
			printf("N __ N\n");
		else
			printf("%d __ %d\n", *(stacks.stackA)[j], *(stacks.stackB)[j]);
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
	stacks->stackA = malloc(sizeof(int *) * i);
	stacks->stackB = malloc(sizeof(int *) * i);
	stacks->size = i;
	start_stack(stacks->stackB, i);
}
