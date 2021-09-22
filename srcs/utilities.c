/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:01:24 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:43:01 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**						# Utilities #
**
**			This is a collection of functions that are used throughout the
**			program. 
**
**			error_message is called when an error occurs. It is used during the
**			argument validation.
**
**			free_stack is a simple free function. It is called when the stack
**			is sorted, and frees the memory allocations we made for each stack.
**
**			ft_strcmp compares two strings, returning a 0 if they are equal,
**			and 1 if they are different. It is used by operations1/2 to check
**			the input.
**
**			operations1/2 are functions which receive a call to perfom an
**			operation and direct us to that specific operation function.
**			operations1 handles calls to swap and push, while operations2
**			handles calls to rotate and reverse rotate.
*/

int	error_message(void)
{
	ft_putstr_fd("Error\n", 1);
	return (1);
}

int	free_stack(t_stacks *s, int i)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	else
		return (0);
}

void	operations1(t_stacks *s, char *op)
{
	if (ft_strcmp(op, "sa"))
		swap(&(s->a));
	else if (ft_strcmp(op, "sb"))
		swap(&(s->b));
	else if (ft_strcmp(op, "ss"))
	{
		swap(&(s->a));
		swap(&(s->b));
	}
	else if (ft_strcmp(op, "pa"))
		push(&(s->b), &(s->a), s->size);
	else if (ft_strcmp(op, "pb"))
		push(&(s->a), &(s->b), s->size);
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
}

void	operations2(t_stacks *s, char *op)
{
	if (ft_strcmp(op, "ra"))
		rotate(&(s->a), s->size);
	else if (ft_strcmp(op, "rb"))
		rotate(&(s->b), s->size);
	else if (ft_strcmp(op, "rr"))
	{
		rotate(&(s->a), s->size);
		rotate(&(s->b), s->size);
	}
	else if (ft_strcmp(op, "rra"))
		reverse_rotate(&(s->a), s->size);
	else if (ft_strcmp(op, "rrb"))
		reverse_rotate(&(s->b), s->size);
	else if (ft_strcmp(op, "rrr"))
	{
		reverse_rotate(&(s->a), s->size);
		reverse_rotate(&(s->b), s->size);
	}
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
}
