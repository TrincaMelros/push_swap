/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:53:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/05/25 16:35:37 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	swap(int **a);
void	push(int **a, int **b, int i);
void	rotate(int **a, int i);
void	reverse_rotate(int **a, int i);

void	start_stack(int **a, int i);
void	*add_stack(int i);
void	stack_printer(int **a, int **b, int i);
int		ft_atoi(const char *nptr);

#endif
