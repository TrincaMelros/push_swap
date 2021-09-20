/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 11:30:30 by malmeida         ###   ########.fr       */
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
	stack_printer(stacks);
	return (0);
}
