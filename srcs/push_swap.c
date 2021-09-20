/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 10:46:18 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**								# Smallest Function #
**
**			This function searches for the smallest number in the array. It
**			also keeps track of which numbers have already been "found" through
**			the zero_array, making sure they're not included in the next
**			searches. It returns an int f, which is the position in the array
**			of the smallest argument.
*/

int	is_smallest(int args, int *arg_array, int **zero_array)
{
	int	i;
	int	f;
	int	small;

	i = 0;
	while ((*zero_array)[i] == 1)
		i++;
	f = i;
	small = arg_array[i];
	i++;
	while (i < args)
	{
		if (arg_array[i] < small && (*zero_array)[i] == 0)
		{
			small = arg_array[i];
			f = i;
		}
	i++;
	}
	return (f);
}

/*
**								# Array Sorter #
**
**			This function receives the three arrays already created, and
**			replaces the numbers on stack_array by their 
**			{0, 1, 2, ..., N} equivalent, while maintaining their position
**			in the array. is_smallest() is called to find each number in
**			an ascending order. When one is found, it is placed on stack_array
**			and its position is changed on zero_array to 1, so we know not to
**			consider the number in the next search.
*/

void	array_sorter(int a, int **zero_array, int *arg_array, int **stack_array)
{
	int	i;
	int	f;

	i = 0;
	while (i < a)
	{
		f = is_smallest(a, arg_array, zero_array);
		(*stack_array)[f] = i;
		(*zero_array)[f] = 1;
		i++;
	}
}

/*
**								# Array Starter #
**
**			This function receives the array filled with the args and prepares
**			its sorting. It creates two additional arrays, one (zero_array) 
**			that is filled with 0s and will be used to keep track of what
**			numbers are already sorted, and another (arg_array) that will save
**			the original position of the args.
**
**			It will then call on array_sorter() to actually organize and sort
**			the args to {0, 1, 2, ..., N} and keep them in their original
**			position.
*/

void	array_starter(int args, int **stack_array)
{
	int	*zero_array;
	int	*arg_array;
	int	i;

	zero_array = malloc(sizeof(int) * args);
	arg_array = malloc(sizeof(int) * args);
	i = -1;
 	while (++i < args)
 	{
		zero_array[i] = 0;
 		arg_array[i] = (*stack_array)[i];
 	}
 	array_sorter(args, &zero_array, arg_array, stack_array);
 	free(zero_array);
	free(arg_array);
}

void	init_stacks(t_stacks *stacks, int i)
{
	stacks->stackA = malloc(sizeof(int *) * i);
	stacks->stackB = malloc(sizeof(int *) * i);
	stacks->size = i;
}

/*
**								# Main Function #
**
**			The Push_Swap program aims to use two stacks to sort a list of
**			integers. It uses a modified Radix Sort to achieve this.
**
**			The first step is to receive and parse the list of arguments,
**			making sure the list is valid (STILL NEED TO DO THIS).
**			
**			After the arguments are validated, we need to convert the args to
**			a list of {0, 1, 2, ..., N}. This is done through the array_sorter
**			function and its childs, and it will help in applying the Radix
**			sort algorithm.
*/

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (argc - 1));
	i = -1;
	while (++i < argc - 1)
		array[i] = ft_atoi(argv[1 + i]);
	array_starter(i, &array);
	init_stacks(&stacks, i);
	start_stack(stacks.stackB, i);
	i = -1;
	while (++i < argc - 1)
		stacks.stackA[i] = add_stack(array[i]);
	stack_printer(stacks.stackA, stacks.stackB, i);
	return (0);
}
