/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:02:32 by malmeida          #+#    #+#             */
/*   Updated: 2021/05/24 12:34:43 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int **a, int **b, int i)
{
	int f;

	f = 0;
	while (f < i)
	{
		a[f] = a[f + 1];
		f++;
	}
}

void	swap(int **a)
{
	int *temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	start_stack(int **a, int i)
{

	while (i)
	{
		a[i - 1] = NULL;
		i--;
	}
}

void	printer(int **a, int **b, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (b[j] == NULL && a[j] != NULL)
			printf("%d __ N\n", *a[j]);
		else if (a[j] == NULL && b[j] != NULL)
			printf("N __ %d\n", *b[j]);
		else if (a[j] == NULL && b[j] == NULL)
			printf("N __ N\n");
		else
			printf("%d __ %d\n", *a[j], *b[j]);
		j++;
	}
	printf("\nA __ B\n");
}

int 	*add_stack(int i)
{
	int *x;

	x = malloc(sizeof(int *));
	*x = i;
	return (x);
}

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
	printer(stackA, stackB, i);
	printf("________________\n");
	swap(stackA);
	printer(stackA, stackB, i);
	return (0);
}
