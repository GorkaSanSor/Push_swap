/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:41:41 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/30 18:19:52 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	while (*a)
	{
		ft_set_index(*a);
		ft_set_index(*b);
		ft_set_target(*a, *b);
		ft_set_cost(*a, ft_stack_size(*a), ft_stack_size(*b));
		ft_cheap_to_top(a, b);
		ft_pb(a, b);
	}
	ft_set_index(*b);
	ft_max_to_top(b);
	while (*b)
		ft_pa(a, b);
}
