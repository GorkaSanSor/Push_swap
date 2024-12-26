/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:20:10 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/26 14:43:48 by gsantill         ###   ########.fr       */
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
	free(split);	// free the first array of pointers
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

void	ft_exit_error(t_stack **head_a, t_stack **head_b)
{
	if (head_a == NULL || *head_a != NULL)
		ft_free_stack(head_a);
	if (head_b == NULL || *head_b != NULL)
		ft_free_stack(head_b);
	ft_printf("Exited due to an error");
	exit(1);
}

//Crea un temp_array concatenando todos los argumentos separados por espacios
char *ft_create_temp_array(char **argv)
{
	char	*temp;
	char	*joined;
	int		i;

	temp = ft_strdup("");
	if (!temp)
		return (NULL);

	i = 1;
	while (argv[i])
	{
		joined = ft_strjoin_addspace(temp, argv[i]);
		free(temp);
		if (!joined)
			return (NULL);
		temp = joined;
		i++;
	}

	return (temp);
}

