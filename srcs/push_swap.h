/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:41:22 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/24 11:18:44 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --------------------------C STANDARD LIBRARIES-----------------------------*/
// # include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
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

nbr: El valor del número almacenado en ese nodo.
index: El índice de la posición del número.
*next: Puntero al siguiente nodo en la pila.*/

typedef struct s_stack
{
	long			nbr;
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
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
//void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

/*---------------------------------MAIN SUB_FT--------------------------------*/

int		ft_check_digits(char *str);
int		ft_duplicates(char **split, int word);
int		ft_maxint(char **split, int word);
int		ft_split_count(char **split);

/*------------------------------------UTILS-----------------------------------*/

void	ft_print_stack(t_stack *stack);
t_stack *ft_stack_new(int nbr);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_free_split(char **split);
void	ft_free_utils(t_utils *utils);
void	ft_free_stack(t_stack **stack);
void	ft_free_all(t_stack **stack_a, t_stack **stack_b, t_utils *utils);
void	ft_check_errors(int argc, char **argv, t_utils *utils, t_stack **stack_a);
void	ft_error_exit(int err_type, t_utils *utils, t_stack **stack);
int		ft_stack_is_sorted(t_stack *stack);
int 	ft_min_num(t_stack *stack);
int		ft_max_num(t_stack *stack);
int		ft_find_index(t_stack *stack, int nbr);
int		ft_find_index_a(t_stack *stack_a, int to_push);
int		ft_find_index_b(t_stack *stack_b, int to_push);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_last_num(t_stack *stack);
int		ft_cost_rr_b(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rrr_b(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rrarb_b(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rarrb_b(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rr_a(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rrr_a(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rrarb_a(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_cost_rarrb_a(t_stack *stack_a, t_stack *stack_b, int nbr);
int		ft_rot_min_cost_to_a(t_stack *stack_a, t_stack *stack_b);
int		ft_rot_min_cost_to_b(t_stack *stack_a, t_stack *stack_b);
int		ft_downdown(t_stack **stack_a, t_stack **stack_b, int n, char *stack);
int		ft_upup(t_stack **stack_a, t_stack **stack_b, int n, char *stack);
int		ft_updown(t_stack **stack_a, t_stack **stack_b, int n, char *stack);
int		ft_downup(t_stack **stack_a, t_stack **stack_b, int n, char *stack);
void	ft_sort_more_than_3_in_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_sort_b(t_stack **stack_a);
t_stack	*ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a);


/*--------------------------------INSTRUCTIONS--------------------------------*/

// swap the first 2 elements at the top of stack a
void	ft_sa(t_stack **stack_a);
// swap the first 2 elements at the top of stack b
void	ft_sb(t_stack **stack_b);
// sa and sb at the same time
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// take the first element at the top of b and put it at the top of a
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
// take the first element at the top of a and put it at the top of b
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
// The first element of a becomes the last one
void	ft_ra(t_stack **stack_a);
// The first element of b becomes the last one
void	ft_rb(t_stack **stack_b);
// ra and rb at the same time
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
// The last element of a becomes the first one
void	ft_rra(t_stack **stack_a);
// The last element of b becomes the first one
void	ft_rrb(t_stack **stack_b);
// rra and rrb at the same time
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif