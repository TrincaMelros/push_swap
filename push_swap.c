/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/17 13:09:00 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(int z, int *arg_array, int *zero_array)
{
	int	i;

	i = 0;
	while (arg_array[i])
	{
		while (zero_array[i] == 1)
			i++;
		if (z <= arg_array[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	array_sorter(int a, int *zero_array, int *arg_array, int **stack_array)
{
	int	i;
	int	f;

	i = 0;
	while (i < a)
	{
		f = 0;
		while (arg_array[f])
		{
			if (is_smallest(arg_array[f]) && !zero_array[f])
			{
				stack_array[f] = i;
			}
		}
		i++;
	}
}

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
	array_sorter(args, zero_array, arg_array, stack_array);
	free(zero_array);
	free(arg_array);
}

int	main(int argc, char **argv)
{
/*
	int	**stackA;
	int	**stackB;
*/
	int	*arg_array;
	int	i;

	i = -1;
	arg_array = malloc(sizeof(int) * (argc - 1));
	while (++i < argc - 1)
		arg_array[i] = ft_atoi(argv[1 + i]);
	array_starter(argc - 1, &arg_array);
	i = 0;
/*
	i = 0;
	while (i < argc - 1)
	{
		printf("Arg %d is %d\n", i, arg_array[i]);
		i++;
	}
	stackA = malloc(sizeof(int *) * (argc - 1));
	if (!stackA)
		return (0);
	stackB = malloc(sizeof(int *) * (argc - 1));
	if (!stackB)
		return (0);
	while (argc - 1 - i)
	{
		stackA[i] = add_stack(ft_atoi(argv[1 + i]));
		i++;
	}
	start_stack(stackB, i);
	stack_printer(stackA, stackB, i);
	printf("________________\n");
	operations(stackA, stackB, i, "pa");
	operations(stackA, stackB, i, "pa");
	stack_printer(stackA, stackB, i);
	printf("________________\n");
	operations(stackA, stackB, i, "rrr");
	stack_printer(stackA, stackB, i);
	printf("________________\n");
*/
	return (0);
}
