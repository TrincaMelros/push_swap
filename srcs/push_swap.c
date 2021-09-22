/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:43:41 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**						# Main Function #
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

	if (argc < 3)
		return (0);
	if (arg_validation(argv, argc - 1))
		return (error_message());
	initialize_stacks(&stacks, argv, argc - 1);
	if (is_sorted(&stacks))
		return (free_stack(&stacks, 1));
	stack_sorter(&stacks);
	return (free_stack(&stacks, 0));
}
