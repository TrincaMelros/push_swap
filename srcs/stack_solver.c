/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:51:03 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 16:04:58 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = stacks->size - 1;
	while (i)
	{
		if (*(stacks->stackA)[i] > *(stacks->stackA)[i - 1])
			i--;
		else
			return (0);
	}
	return (1);

}

void	stack_solver(t_stacks *stacks)
{
	if (stacks->size < 2)
		exit(0);
	else if (stacks->size > 1 && stacks->size < 6)
		printf("WAT IT DO");
	else if (stacks->size > 5)
		radix_sort(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	num;
	int	max_bits;
	int	i;
	int	f;

	max_bits = 0;
	while ((stacks->size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		f = 0;
		while (f < stacks->size)
		{
			num = *(stacks->stackA)[0];
			if (((num >> i) & 1) == 1)
				operations(stacks, "ra");
			else
				operations(stacks, "pb");
			f++;
		}
		while ((stacks->stackB[0]) != NULL)
			operations(stacks, "pa");
		i++;
	}
}
