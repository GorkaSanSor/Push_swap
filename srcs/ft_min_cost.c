/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:21:45 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:22:05 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the cost of moving each element from stack a to b.
void	ft_set_cost(t_stack *a, int size_a, int size_b)
{
	int	half_a;
	int	half_b;

	half_a = size_a / 2;
	half_b = size_b / 2;
	while (a != NULL)
	{
		if (a->index <= half_a && a->target <= half_b)
			a->cost = a->index + a->target;
		else if (a->index <= half_a && a->target > half_b)
			a->cost = a->index + (size_b - a->target);
		else if (a->index > half_a && a->target <= half_b)
			a->cost = (size_a - a->index) + a->target;
		else
			a->cost = (size_a - a->index) + (size_b - a->target);
		a = a->next;
	}
}

// Finds the index of the target for a number in stack b.
static int	ft_middle_target_index(int to_push, t_stack *b)
{
	int		indx;
	t_stack	*current;

	current = b;
	if (to_push > b->nbr && to_push < ft_last_num(b)->nbr)
		indx = b->index;
	else
	{
		while (to_push > current->nbr && current != NULL)
			current = current->next;
		while (to_push < current->nbr && current != NULL
			&& ft_last_num(current)->index != current->index)
			current = current->next;
		indx = current->index;
	}
	return (indx);
}

// Assigns a target index to each element in stack a based on stack b.
void	ft_set_target(t_stack *a, t_stack *b)
{
	t_stack	*min;
	t_stack	*max;

	max = ft_max_num(b);
	min = ft_min_num(b);
	while (a != NULL)
	{
		if (a->nbr < min->nbr || a->nbr > max->nbr)
			a->target = max->index;
		else
			a->target = ft_middle_target_index(a->nbr, b);
		a = a->next;
	}
}

// Finds the element with the minimum cost in a stack.
t_stack	*ft_find_min_cost(t_stack *stack)
{
	t_stack	*min_cost;

	min_cost = stack;
	while (stack != NULL)
	{
		if (stack->cost < min_cost->cost)
			min_cost = stack;
		stack = stack->next;
	}
	return (min_cost);
}

// Moves the element with the minimum cost to the top of stack a.
void	ft_cheap_to_top(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;
	int		size_a;
	int		half_a;
	int		size_b;
	int		half_b;

	min_cost = ft_find_min_cost(*a);
	size_a = ft_stack_size(*a);
	half_a = size_a / 2;
	size_b = ft_stack_size(*b);
	half_b = size_b / 2;
	while ((*a)->index != min_cost->index || (*b)->index != min_cost->target)
	{
		if (min_cost->index <= half_a && min_cost->target <= half_b)
			ft_up(a, b, min_cost);
		else if (min_cost->index > half_a && min_cost->target > half_b)
			ft_down(a, b, min_cost);
		else if (min_cost->index <= half_a && min_cost->target > half_b)
			ft_up_down(a, b, min_cost);
		else
			ft_down_up(a, b, min_cost);
	}
}
