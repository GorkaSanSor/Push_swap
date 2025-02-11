/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:11:51 by gsantill          #+#    #+#             */
/*   Updated: 2025/02/11 14:53:36 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if the stack is already sorted in ascending order.
int	ft_stack_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Sorts a stack containing exactly 3 numbers.
void	ft_sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first > second && second > third)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
	else if (first > second && second < third && first < third)
		ft_sa(stack);
	else if (first < second && first > third && second > third)
		ft_rra(stack);
	else if (second > first && second > third && third > first)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (first > second && first > third && second < third)
		ft_ra(stack);
}

// Sorts a stack containing exactly 4 numbers.
void	ft_sort_four(t_stack **a, t_stack **b)
{
	if (ft_min_num(*a)->nbr == (*a)->nbr)
		ft_pb(a, b);
	else if (ft_min_num(*a)->nbr == (*a)->next->nbr)
	{
		ft_sa(a);
		ft_pb(a, b);
	}
	else if (ft_min_num(*a)->nbr == (*a)->next->next->nbr)
	{
		ft_rra(a);
		ft_rra(a);
		ft_pb(a, b);
	}
	else
	{
		ft_rra(a);
		ft_pb(a, b);
	}
	ft_sort_three(a);
	ft_pa(a, b);
}

// Sorts a stack containing exactly 5 numbers.
void	ft_sort_five(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_sort_four(a, b);
	if ((*b)->nbr < (*a)->next->nbr || (*b)->nbr > (*a)->next->next->next->nbr)
	{
		ft_pa(a, b);
		if ((*a)->nbr > ft_last_num(*a)->nbr)
			ft_ra(a);
		else if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a);
	}
	else if ((*b)->nbr > (*a)->next->nbr && (*b)->nbr < (*a)->next->next->nbr)
	{
		ft_ra(a);
		ft_pa(a, b);
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*b)->nbr > (*a)->next->next->nbr \
	&& (*b)->nbr < (*a)->next->next->next->nbr)
	{
		ft_rra(a);
		ft_pa(a, b);
		ft_ra(a);
		ft_ra(a);
	}
}
