/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/05/19 15:40:30 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	rotate(int *a, int i)
{
	int j;
	int	temp;

	j = 0;
	temp = a[0];
	while (j < i)
	{
		
	}
}
*/
void	swap(int *a)
{
	int temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	printer(int *a, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		printf("%d\n", a[j]);
		j++;
	}
}

int	main(int argc, char **argv)
{

	int	stackA[argc - 1];
	int	i;

	i = 0;
	while (argc - 1 - i)
	{
		stackA[i] = ft_atoi(argv[1 + i]);
		i++;
	}
	printer(stackA, i);
	printf("________________\n");
	swap(stackA);
	printer(stackA, i);
	return (0);
}
