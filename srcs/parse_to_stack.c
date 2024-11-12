/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:04:59 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/12 13:51:14 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "push_swap.h"

int	parse_to_stack(char *arg, t_stack **stack_a)
{
	if (ft_check_argv(arg, split, *word) != 0)
	{
		ft_printf("Error: Argumentos inválidos.\n");
		return (1);  // Error encontrado en las verificaciones
	}
	char **split = ft_split(arg, ' ');
	int j = 0;

	while (split[j])
	{
		t_stack *new_node = new_stack(ft_atoi(split[j]));
		if (!new_node)
		{
			ft_free_split(split);
			return (1);  // Error en creación de nodo
		}
		add_node_to_end(stack_a, new_node);
		j++;
	}
	ft_free_split(split);
	return (0);  // Inserción exitosa
}*/

