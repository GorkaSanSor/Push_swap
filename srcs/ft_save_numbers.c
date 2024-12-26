/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:37:38 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/26 15:23:34 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Save the numbers into the list
t_stack *ft_save_numbers(int word, char **split)
{
	t_stack	*head_a;
	int		i;
	int		num;
	
	head_a = NULL;
	i = 0;
	while (i < word)
	{
		num = ft_atoi(split[i]);
		if (i == 0)
			head_a = ft_stack_new(num);
		else
			ft_stack_add_back(&head_a, ft_stack_new(num));
		i++;
	}
	return (head_a);
}
