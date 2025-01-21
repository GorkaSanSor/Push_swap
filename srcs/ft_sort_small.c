/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:11:51 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/21 14:13:14 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprueba si la lista está ya ordenada
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

// Sort a stack of 3 nbrs only.
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_stack_is_sorted(*stack_a) == 1)
		return ;
	if (ft_min_num(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if (ft_max_num(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a);
		if (!ft_stack_is_sorted(*stack_a))
			ft_sa(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max_num(*stack_a)) == 1)
			ft_rra(stack_a);
		else
			ft_sa(stack_a);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_min_num(*stack_a) == (*stack_a)->nbr)
		ft_pb(stack_a, stack_b);
	else if(ft_min_num(*stack_a) == (*stack_a)->next->nbr)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (ft_min_num(*stack_a) == (*stack_a)->next->next->nbr)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}
/*
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int min_index;

	min_index = ft_find_index(*stack_a, ft_min_num(*stack_a));
	if (min_index == 0)
		ft_pb(stack_a, stack_b);
	else if (min_index == 1)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (min_index == 2)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else
	{
		while (min_index++ < 5)
			ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
*/
