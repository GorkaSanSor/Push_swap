/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/12 14:36:47 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*static void	ft_push_swap(t_stack **head_a, t_stack **head_b, int size)
{
	if (size < 2)
		return ;
}*/

int main(int argc, char **argv)
{
	int word;
	t_stack *head_a = NULL;
	t_stack *head_b = NULL;
	t_utils utils;

	word = 0;
	if (argc < 2)
		return (0);
	utils.temp_array = ft_create_temp_array(argv);
	utils.split = ft_split(utils.temp_array, ' ');
	while (utils.split[word])
		word++;
	if (ft_check_argv(utils.temp_array, utils.split, word) == 1)
	{
		ft_free_utils(&utils);
		ft_exit_error(NULL, NULL);
	}
	head_b = NULL;
	head_a = ft_save_numbers(word, utils.split);
	ft_assign_index(head_a, word);
	// Imprimir los stacks
	print_stack(head_a, 'A');
	print_stack(head_b, 'B');
	//ft_push_swap(&head_a, &head_b, word);
	ft_free_stack(&head_a);
	ft_free_stack(&head_b);
	ft_free_utils(&utils);

	return (0);
}