/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:08 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:10:52 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sets the index of all numbers in the stack sequentially.
void	ft_set_index(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack->index = size;
		stack = stack->next;
	}
}
