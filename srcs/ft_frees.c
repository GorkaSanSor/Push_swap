/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:42:09 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/27 12:42:22 by gsantill         ###   ########.fr       */
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
void	ft_free_stack(t_stack **head)
{
	t_stack *current;
	
	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	while (current->ptr_to_next)
	{
		current = current->ptr_to_next;
		free(*head);
		*head = current;
	}
	free(*head);
	*head = NULL;
	return ;
}

void	ft_free_utils(t_utils *utils)
{
	ft_free_split(utils->split);
	utils->split = NULL;
	free(utils->temp_array);
	utils->temp_array = NULL;
}

