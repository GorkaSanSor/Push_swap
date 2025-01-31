/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:11 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:30:17 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the top element from the source stack to the destination stack.
static void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

// Take the first element at the top of b and put it at the top of a.
void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	ft_printf("pa\n");
}

// Take the first element at the top of a and put it at the top of b.
void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
