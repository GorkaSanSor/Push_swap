/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:45:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/24 11:46:00 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_downdown(t_stack **stack_a, t_stack **stack_b, int n, char *stack)
{
	if (ft_strcmp(stack, "stack_a") == 0)
	{
		while ((*stack_a)->nbr != n && ft_find_index_b(*stack_b, n) > 0)
			ft_rr(stack_a, stack_b);
		while ((*stack_a)->nbr != n)
			ft_ra(stack_a);
		while (ft_find_index_b(*stack_b, n) > 0)
			ft_rb(stack_b);
		ft_pb(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	else
	{
		while ((*stack_b)->nbr != n && ft_find_index_a(*stack_a, n) > 0)
			ft_rr(stack_a, stack_b);
		while ((*stack_b)->nbr != n)
			ft_rb(stack_b);
		while (ft_find_index_a(*stack_a, n) > 0)
			ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	return (-1);
}

int	ft_upup(t_stack **stack_a, t_stack **stack_b, int n, char *stack)
{
	if (ft_strcmp(stack, "stack_a") == 0)
	{
		while ((*stack_a)->nbr != n && ft_find_index_b(*stack_b, n) > 0)
			ft_rrr(stack_a, stack_b);
		while ((*stack_a)->nbr != n)
			ft_rra(stack_a);
		while (ft_find_index_b(*stack_b, n) > 0)
			ft_rrb(stack_b);
		ft_pb(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	else
	{
		while ((*stack_b)->nbr != n && ft_find_index_a(*stack_a, n) > 0)
			ft_rrr(stack_a, stack_b);
		while ((*stack_b)->nbr != n)
			ft_rrb(stack_b);
		while (ft_find_index_a(*stack_a, n) > 0)
			ft_rra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	return (-1);
}

int	ft_updown(t_stack **stack_a, t_stack **stack_b, int n, char *stack)
{
	if (ft_strcmp(stack, "stack_a") == 0)
	{
		while ((*stack_a)->nbr != n)
			ft_rra(stack_a);
		while (ft_find_index_b(*stack_b, n) > 0)
			ft_rb(stack_b);
		ft_pb(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	else
	{
		while (ft_find_index_a(*stack_a, n) > 0)
			ft_rra(stack_a);
		while ((*stack_b)->nbr != n)
			ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	return (-1);
}

int	ft_downup(t_stack **stack_a, t_stack **stack_b, int n, char *stack)
{
	if (ft_strcmp(stack, "stack_a") == 0)
	{
		while ((*stack_a)->nbr != n)
			ft_ra(stack_a);
		while (ft_find_index_b(*stack_b, n) > 0)
			ft_rrb(stack_b);
		ft_pb(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	else
	{
		while (ft_find_index_a(*stack_a, n) > 0)
			ft_ra(stack_a);
		while ((*stack_b)->nbr != n)
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
	}
	return (-1);
}