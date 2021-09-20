/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:53:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/20 10:25:39 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct	s_stacks {
	int	**stackA;
	int	**stackB;
	int	size;
}				t_stacks;

void	swap(int **a);
void	push(int **a, int **b, int i);
void	rotate(int **a, int i);
void	reverse_rotate(int **a, int i);
void	operations(int **stackA, int **stackB, int i, char *op);

void	start_stack(int **a, int i);
void	*add_stack(int i);
void	stack_printer(int **a, int **b, int i);
int		ft_strcmp(char *s1, char *s2);

#endif
