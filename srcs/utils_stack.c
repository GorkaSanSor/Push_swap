/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:47:09 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/20 14:19:03 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the smallest nbr of the stack
int ft_min_num(t_stack *stack)
{
	int	min;
	
	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

// Finds the bigest nbr of the stack
int	ft_max_num(t_stack *stack)
{
	int	max;
	
	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
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

t_stack	*ft_last_num(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}