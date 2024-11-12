/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:07:01 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/11 15:28:13 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack, char stack_name)
{
    t_stack *temp = stack;
    ft_printf("Stack %c: ", stack_name);
    while (temp)
    {
        ft_printf("%d ", temp->number);
        temp = temp->next;
    }
    ft_printf("\n");
}
