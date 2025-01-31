/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:45:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:24:18 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotates one or two stacks up until the target element is at the top.
void	ft_up(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index && (*b)->index != cost->target)
			ft_rr(a, b);
		else if ((*a)->index != cost->index)
			ft_ra(a);
		else if ((*b)->index != cost->target)
			ft_rb(b);
	}
}

// Rotates one or two stacks stacks down until the target element is at the top.
void	ft_down(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index && (*b)->index != cost->target)
			ft_rrr(a, b);
		else if ((*a)->index != cost->index)
			ft_rra(a);
		else if ((*b)->index != cost->target)
			ft_rrb(b);
	}
}

// Rotates stack a up and stack b down until the target elements are at the top.
void	ft_up_down(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index)
			ft_ra(a);
		if ((*b)->index != cost->target)
			ft_rrb(b);
	}
}

// Rotates stack a down and stack b up until the target elements are at the top.
void	ft_down_up(t_stack **a, t_stack **b, t_stack *cost)
{
	while ((*a)->index != cost->index || (*b)->index != cost->target)
	{
		if ((*a)->index != cost->index)
			ft_rra(a);
		if ((*b)->index != cost->target)
			ft_rb(b);
	}
}
