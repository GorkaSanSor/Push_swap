/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_min_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:00 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/24 13:18:43 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot_min_cost_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp_b;
	int cost;
	int cost_rrr;
	int cost_rrarb;
	int cost_rarrb;
	
	if (!stack_a || !stack_b)
		return (UNKNOWN_ERROR);
	tmp_b = stack_b;
	cost = ft_cost_rr_a(stack_a, stack_b, tmp_b->nbr);
	while (tmp_b)
	{
		cost_rrr = ft_cost_rrr_a(stack_a, stack_b, tmp_b->nbr);
		cost_rrarb = ft_cost_rrarb_a(stack_a, stack_b, tmp_b->nbr);
		cost_rarrb = ft_cost_rarrb_a(stack_a, stack_b, tmp_b->nbr);
		if (cost > cost_rrr)
			cost = cost_rrr;
		if (cost > cost_rrarb)
			cost = cost_rrarb;
		if (cost > cost_rarrb)
			cost = cost_rarrb;
		tmp_b = tmp_b->next;
	}
	return (cost);
}

int	ft_rot_min_cost_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp_a;
	int cost;
	int cost_rrr;
	int cost_rrarb;
	int cost_rarrb;
	
	if (!stack_a || !stack_b)
		return (UNKNOWN_ERROR);
	tmp_a = stack_a;
	cost = ft_cost_rr_b(stack_a, stack_b, tmp_a->nbr);
	while (tmp_a)
	{
		cost_rrr = ft_cost_rrr_b(stack_a, stack_b, tmp_a->nbr);
		cost_rrarb = ft_cost_rrarb_b(stack_a, stack_b, tmp_a->nbr);
		cost_rarrb = ft_cost_rarrb_b(stack_a, stack_b, tmp_a->nbr);

		if (cost > cost_rrr)
			cost = cost_rrr;
		if (cost > cost_rrarb)
			cost = cost_rrarb;
		if (cost > cost_rarrb)
			cost = cost_rarrb;
		tmp_a = tmp_a->next;
	}
	return (cost);
}