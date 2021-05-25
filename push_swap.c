/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/05/25 16:34:28 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{

	int	*stackA[argc - 1];
	int *stackB[argc - 1];
	int	i;

	i = 0;
	while (argc - 1 - i)
	{
		stackA[i] = add_stack(ft_atoi(argv[1 + i]));
		i++;
	}
	start_stack(stackB, i);
	stack_printer(stackA, stackB, i);
	printf("________________\n");
	reverse_rotate(stackA, i);
	stack_printer(stackA, stackB, i);
	rotate(stackA, i);
	stack_printer(stackA, stackB, i);
	printf("\n%d\n", i);
	return (0);
}
