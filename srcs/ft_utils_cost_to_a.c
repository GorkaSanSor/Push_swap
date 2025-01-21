/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_cost_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:53:17 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/20 14:17:25 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate cost for rr (rotate both stacks simultaneously)
int	ft_cost_rr_a(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	cost;

	cost = ft_find_index_a(stack_a, nbr);
	if (cost < ft_find_index_b(stack_b, nbr))
		cost = ft_find_index_b(stack_b, nbr);
	return (cost);
}
// Calculate cost for rrr (reverse rotate both stacks simultaneously)
int	ft_cost_rrr_a(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int cost;

	cost = 0;
	if (ft_find_index_a(stack_a, nbr) > 0)
		cost = ft_stack_size(stack_a) - ft_find_index_a(stack_a, nbr);
	if (cost < (ft_stack_size(stack_b) - ft_find_index(stack_b, nbr)))
		cost = ft_stack_size(stack_b) - ft_find_index(stack_b, nbr);
	return (cost);
}

// Calculate cost for rra and rb (rotate stack_b and reverse rotate stack_a)
int	ft_cost_rrarb_a(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int cost;

	cost = 0;
	if (ft_find_index(stack_b, nbr) > 0)
		cost = ft_stack_size(stack_a) - ft_find_index(stack_b, nbr);
	cost += ft_find_index_a(stack_a, nbr);
	return (cost);
}

// Calculate cost for ra and rrb (rotate stack_a and reverse rotate stack_b)
int	ft_cost_rarrb_a(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int cost;

	cost = 0;
	if (ft_find_index_a(stack_a, nbr) > 0)
		cost = ft_stack_size(stack_a) - ft_find_index_a(stack_a, nbr);
	cost += ft_find_index(stack_b, nbr);
	return (cost);
}