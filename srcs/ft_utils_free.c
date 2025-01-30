/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:42:09 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/30 18:11:49 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	word;

	word = 0;
	if (split == NULL)
		return ;
	while (split[word])
	{
		free(split[word]);
		word++;
	}
	free(split);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current->next)
	{
		current = current->next;
		free(*stack);
		*stack = current;
	}
	free(*stack);
	*stack = NULL;
	return ;
}

void	ft_free_utils(t_utils *utils)
{
	ft_free_split(utils->split);
	utils->split = NULL;
	free(utils->temp_array);
	utils->temp_array = NULL;
}

void	ft_free_all(t_stack **a, t_stack **b, t_utils *utils)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_free_utils(utils);
}
