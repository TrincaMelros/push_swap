/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:45:37 by malmeida          #+#    #+#             */
/*   Updated: 2021/09/22 16:43:32 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**					# Argument Validation #
**
**			This file contains all functions related to the argument
**			validation. arg_validation receives the args from the main function
**			and checks them. First it checks if any of the numbers is bigger or
**			smaller than an int. Then it uses is_digit to check if all the args
**			are digits. Finally, it checks if there are duplicate args with the
**			duplicate_validation function. If any of them find an invalid arg,
**			they return 1, indicating a problem. If all args are valid, they
**			return 0.
*/			

int	arg_validation(char **args, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
			return (1);
		i++;
	}
	i = 1;
	while (i <= size)
	{
		if (is_digit(args[i]))
			return (1);
		i++;
	}
	if (duplicate_validation(args, size))
		return (1);
	return (0);
}

int	is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] == '-' || s[i + 1] == '+')
				return (1);
			i++;
		}
		if (s[i] > '9' || s[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	duplicate_validation(char **args, int size)
{
	int	*array;
	int	i;
	int	f;

	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		array[i] = ft_atoi(args[i + 1]);
	f = 0;
	if (is_duplicate(array, size))
		f = 1;
	free (array);
	return (f);
}

int	is_duplicate(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
