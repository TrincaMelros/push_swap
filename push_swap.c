/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/15 11:58:12 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	**stackA;
	int	**stackB;
	int	i;

	i = 0;
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
	return (0);
}
