/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:53:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/21 14:24:58 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_stacks {
	int	**sta;
	int	**stb;
	int	size;
}				t_stacks;

/* Arguments sorter */
int		is_smallest(int args, int *arg_array, int **zero_array);
void	array_sorter(int a, int **zero_array, \
		int *arg_array, int **stack_array);
void	array_starter(int args, int **stack_array);
void	arg_checker(char **args, int size);

/* Stack Operations */
void	swap(int **a);
void	push(int **a, int **b, int size);
void	rotate(int **a, int size);
void	reverse_rotate(int **a, int size);

/* Stack Utilities */
int		is_sorted(t_stacks *stacks);
void	start_stack(int **a, int i);
void	*add_stack(int i);
void	stack_printer(t_stacks stacks);
void	init_stacks(t_stacks *stacks, int i);

/* Stack Solver */
void	stack_solver(t_stacks *stacks);
void	three_sorter(t_stacks *stacks);
void	four_sorter(t_stacks *stacks);
void	five_sorter(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);

/* Utilities */
void	operations1(t_stacks *stacks, char *op);
void	operations2(t_stacks *stacks, char *op);
void	is_duplicate(int *array, int size);
int		is_valid(char *s);
int		ft_strcmp(char *s1, char *s2);

/* Free the Homies */
void	garbage_collector(t_stacks *s, int f);

#endif
