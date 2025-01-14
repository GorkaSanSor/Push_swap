/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:47:09 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:34:11 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the smallest number of the stack
int ft_min_num(t_stack *stack)
{
	int	min;
	
	min = stack->number;
	while (stack)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	return (min);
}

// Finds the bigest number of the stack
int	ft_max_num(t_stack *stack)
{
	int	max;
	
	max = stack->number;
	while (stack)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	return (max);
}

// Find the index of a number
int	ft_find_index(t_stack *stack, int number)
{
	int	index;

	index = 0;
	while (stack->number != number)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	ft_stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}