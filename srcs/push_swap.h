/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:41:22 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/08 14:12:12 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --------------------------C STANDARD LIBRARIES-----------------------------*/
// # include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

/* ----------------------------------ERRORS-----------------------------------*/

# define WRONG_ARGS 1
# define INVALID_DIGIT 2
# define DUPLICATES 3
# define OVERFLOW 4
# define UNKNOWN_ERROR 5

/* --------------------------------PROTOTYPES---------------------------------*/

/*Estructura s_stack. Cada nodo tiene:

number: El valor del número almacenado en ese nodo.
index: El índice de la posición del número.
pos: La posición actual del número en la pila.
target_pos: La posición objetivo para este número después de la ordenación.
cost_a y cost_b: Costo asociado con mover un número de una pila a otra.
*ptr_to_next: Puntero al siguiente nodo en la pila.*/

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*ptr_to_next;
}	t_stack;

typedef struct s_utils
{
	char **split;
	char *temp_array;
}	t_utils;

/*-----------------------------------MAIN FT----------------------------------*/

char	*ft_create_temp_array(char **argv);
int		ft_check_argv(char *temp_array, char **split, int word);
t_stack *ft_save_numbers(int word, char **split);

/*---------------------------------MAIN SUB_FT--------------------------------*/

int		ft_check_digits(char *str);
int		ft_duplicates(char **split, int word);
int		ft_maxint(char **split, int word);
int		ft_split_count(char **split);

/*------------------------------------UTILS-----------------------------------*/

t_stack *ft_stack_new(int number);
void	ft_stack_add_back(t_stack **head, t_stack *new);
void	ft_free_split(char **split);
void	ft_free_utils(t_utils *utils);
void	ft_free_stack(t_stack **head);
void	ft_error_exit(int err_type, t_utils *utils, t_stack **stack);

/*--------------------------------INSTRUCTIONS--------------------------------*/

void	ft_sa(t_stack **head_a);
void	ft_sb(t_stack **head_b);
void	ft_ss(t_stack **head_a, t_stack **head_b);
void	ft_pa(t_stack **head_a, t_stack **head_b);
void	ft_pb(t_stack **head_a, t_stack **head_b);
void	ft_ra(t_stack **head_a);
void	ft_rb(t_stack **head_b);
void	ft_rr(t_stack **head_a, t_stack **head_b);
void	ft_rra(t_stack **head_a);
void	ft_rrb(t_stack **head_b);
void	ft_rrr(t_stack **head_a, t_stack **head_b);

#endif