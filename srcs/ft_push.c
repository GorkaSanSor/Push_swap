/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:11 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/08 12:56:17 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack *current;

	if (*src == NULL)
		return ;
	current = (*src)->ptr_to_next;
	(*src)->ptr_to_next = *dst;
	*dst = *src;
	*src = current;
}

void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_b, head_a);
}
void	ft_pb(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_a, head_b);
}