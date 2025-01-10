/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:47:09 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 13:33:12 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the smallest number of the stack
int ft_min_num(t_stack *head)
{
	int	min;
	
	min = head->number;
	while (head)
	{
		if (head->number < min)
			min = head->number;
		head = head->next;
	}
	return (min);
}

// Finds the bigest number of the stack
int	ft_max_num(t_stack *head)
{
	int	max;
	
	max = head->number;
	while (head)
	{
		if (head->number > max)
			max = head->number;
		head = head->next;
	}
	return (max);
}

// Find the index of a number
int	ft_find_index(t_stack *head, int number)
{
	int	index;

	index = 0;
	while (head->number != number)
	{
		index++;
		head = head->next;
	}
	return (index);
}