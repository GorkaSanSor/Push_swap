/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:41:22 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 16:31:10 by gsantill         ###   ########.fr       */
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
*next: Puntero al siguiente nodo en la pila.*/

typedef struct s_stack
{
	long			number;
	long			index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_utils
{
	char **split;
	char *temp_array;
}	t_utils;

/*-----------------------------------MAIN FT----------------------------------*/

char	*ft_create_temp_array(char **argv);
int		ft_check_argv(char *temp_array, char **split, int word);
t_stack *ft_parse_to_stack(int word, char **split);
void	ft_sort_three(t_stack **head_a);
void	ft_sort_four(t_stack **head_a, t_stack **head_b);
void	ft_sort_five(t_stack **head_a, t_stack **head_b);

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
int		ft_stack_is_sorted(t_stack *head);
int 	ft_min_num(t_stack *head);
int		ft_max_num(t_stack *head);
int		ft_find_index(t_stack *head, int number);

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