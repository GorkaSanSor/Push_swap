/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:08:11 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Determines the sorting algorithm based on the number of elements.
static void	ft_push_swap(t_stack **a, t_stack **b, int split_count)
{
	if (split_count < 2)
		return ;
	else if (split_count == 2 && ft_stack_is_sorted(*a) == 0)
		ft_sa(a);
	else if (split_count == 3 && ft_stack_is_sorted(*a) == 0)
		ft_sort_three(a);
	else if (split_count == 4 && ft_stack_is_sorted(*a) == 0)
		ft_sort_four(a, b);
	else
		ft_sort_big(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_utils	utils;

	a = NULL;
	b = NULL;
	ft_check_errors(argc, argv, &utils, &a);
	ft_push_swap(&a, &b, ft_split_count(utils.split));
	ft_free_all(&a, &b, &utils);
	return (0);
}
