/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:47:09 by gsantill          #+#    #+#             */
/*   Updated: 2025/02/03 12:52:21 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the smallest number in the stack.
t_stack	*ft_min_num(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

// Finds the largest number in the stack.
t_stack	*ft_max_num(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack != NULL)
	{
		if (stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

// Moves the largest number in stack b to the top.
void	ft_max_to_top(t_stack **b)
{
	t_stack	*max;
	int		size_b;
	int		half_b;

	max = ft_max_num(*b);
	size_b = ft_stack_size(*b);
	half_b = size_b / 2;
	if (max->index <= half_b)
	{
		while (max->index != (*b)->index)
			ft_rb(b);
	}
	if (max->index > half_b)
	{
		while (max->index != (*b)->index)
			ft_rrb(b);
	}
}

// Returns the number of elements in the stack.
int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

// Returns the last node of the stack.
t_stack	*ft_last_num(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
