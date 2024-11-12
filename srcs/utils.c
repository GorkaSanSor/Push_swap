/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:20:10 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/12 14:32:54 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	word;

	word = 0;
	if (split == NULL)	// avoids SIGSEV if split is NULL
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
    t_stack *temp;

	if (head == NULL || *head == NULL)
		return ;
	temp = *head;
    while (temp->next)
    {
        temp = temp->next;
		free(*head);
        *head = temp;
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
	if (head_a == NULL || head_a != NULL)
		ft_free_stack(head_a);
	if (head_b == NULL || head_b != NULL)
		ft_free_stack(head_b);
	ft_printf("Error|n");
	exit(1);
}
char	*ft_create_temp_array(char **argv)
{
	int i;
	char *temp_array;
	char *temp2;

	i = 0;
	temp_array = NULL;
	temp2 = NULL;
	while (argv[i])
	{
		temp2 = ft_strdup(temp_array);
		free(temp_array);
		temp_array = ft_strjoin_endspace(temp2, argv[i]);
		free(temp2);
		i++;
	}
	return (temp_array);
}
