/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:53:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:22:07 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_stacks {
	int	*a;
	int	*b;
	int	size;
}				t_stacks;

	/* Argument Validation */
int		arg_validation(char **args, int size);
int		is_digit(char *s);
int		duplicate_validation(char **args, int size);
int		is_duplicate(int *array, int size);

	/* Stack Initializer */
void	initialize_stacks(t_stacks *s, char **args, int i);
void	arg_sorter(t_stacks *s);
void	array_sorter(t_stacks *s, int *arg_array, int **zero_array);
int		is_smallest(t_stacks *s, int *arg_array, int **zero_array);
int		is_sorted(t_stacks *s);

	/* Stack Sorter */
void	stack_sorter(t_stacks *s);
void	three_sorter(t_stacks *s);
void	four_sorter(t_stacks *s);
void	five_sorter(t_stacks *s);
void	radix_sort(t_stacks *s);

	/* Stack Operations */
void	swap(int **a);
void	push(int **a, int **b, int size);
void	rotate(int **a, int size);
void	reverse_rotate(int **a, int size);

	/* Utilities */
int		error_message(void);
int		free_stack(t_stacks *s, int i);
int		ft_strcmp(char *s1, char *s2);
void	operations1(t_stacks *s, char *op);
void	operations2(t_stacks *s, char *op);

#endif
