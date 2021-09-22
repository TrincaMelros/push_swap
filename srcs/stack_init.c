/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:55:42 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:43:50 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**						# Initialize Stacks #
**
**			initialize_stacks is the main function to initialize the stacks and
**			fill them up accordingly.
**			The size is filled up with (argc - 1).
**			StackA is allocated memory, filled with the validated arguments,
**			and then sent over to arg_sorter, where the arguments will be
**			replaced by numbers from {0,..., N}
**			StackB is allocated memory and then filled with -1s, which are
**			there to mark it as empty.
**
**			arg_sorter initializes and allocates two arrays which will help in
**			the parsing of the arguments. The first array is arg_array, which
**			is equal to the unordered stackA and serves to keep the original
**			order. zero_array is an array filled with 0s which helps us track
**			which arguments have already been converted. As each argument is
**			converted, zero_array is filled with a 1 in the equivalent position
**			of it on arg_array.
**
**			array_sorter is the function that actually transforms stackA into
**			an array with numbers from {0,..., N}. It calls on is_smallest to
**			find each number in ascending order. When its found, it is placed
**			stackA and its position is changed on zero_array to 1, so we know
**			not to consider the number in the next search loop.
**
**			is_smallest searches for the smallest number in the array. It
**			returns an int f, which is the position in the array of the
**			smallest argument.
**
**			is_sorted is a simple function which checks if the stack it is
**			given is already sorted.
*/

void	initialize_stacks(t_stacks *s, char **args, int i)
{
	int	j;

	s->a = malloc(sizeof(int) * i);
	j = -1;
	while (++j < i)
		s->a[j] = ft_atoi(args[j + 1]);
	s->b = malloc(sizeof(int) * i);
	j = -1;
	while (++j < i)
		s->b[j] = -1;
	s->size = i;
	arg_sorter(s);
}

void	arg_sorter(t_stacks *s)
{
	int	*zero_array;
	int	*arg_array;
	int	i;

	zero_array = malloc(sizeof(int) * s->size);
	arg_array = malloc(sizeof(int) * s->size);
	i = 0;
	while (i < s->size)
	{
		zero_array[i] = 0;
		arg_array[i] = s->a[i];
		i++;
	}
	array_sorter(s, arg_array, &zero_array);
	free(zero_array);
	free(arg_array);
}

void	array_sorter(t_stacks *s, int *arg_array, int **zero_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size)
	{
		j = is_smallest(s, arg_array, zero_array);
		s->a[j] = i;
		(*zero_array)[j] = 1;
		i++;
	}
}

int	is_smallest(t_stacks *s, int *arg_array, int **zero_array)
{
	int	i;
	int	j;
	int	small;

	i = 0;
	while ((*zero_array)[i] == 1)
		i++;
	j = i;
	small = arg_array[i];
	i++;
	while (i < s->size)
	{
		if (arg_array[i] < small && (*zero_array)[i] == 0)
		{
			small = arg_array[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	is_sorted(t_stacks *s)
{
	int	i;

	i = s->size - 1;
	while (i)
	{
		if (s->a[i] > s->a[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}
