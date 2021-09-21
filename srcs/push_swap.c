/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/21 14:23:56 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
**			a list of {0, 1, 2, ..., N}. This is done through the array_starter
**			function and its childs, and it will help in applying the Radix
**			sort algorithm.
*/

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*array;
	int			i;

	if (argc < 3)
		return (0);
	array = malloc(sizeof(int) * (argc - 1));
	i = -1;
	while (++i < argc - 1)
		array[i] = ft_atoi(argv[1 + i]);
	arg_checker(argv, i);
	is_duplicate(array, i);
	array_starter(i, &array);
	init_stacks(&stacks, i);
	i = -1;
	while (++i < argc - 1)
		stacks.sta[i] = add_stack(array[i]);
	free(array);
	if (is_sorted(&stacks))
		garbage_collector(&stacks, 1);
	stack_solver(&stacks);
	garbage_collector(&stacks, 0);
	return (0);
}
