/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:54:13 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/25 18:50:33 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

//Parsing ------------------------------------/

char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
long int	ft_atoi(const char *nptr, t_stack **a, char **split);
char		*ft_strdup(const char *s);
char		*get_args(int ac, char **av);
int			free_split(char **result);
void		parse_args(int ac, char **av, t_stack **stack_a);

//Stack Utils ---------------------------------/

void		init_stack(t_stack **stack);
void		push(t_stack **stack, int value);
int			pop(t_stack **stack);
int			is_empty(t_stack **stack);
void		free_stack(t_stack **stack);
int			peek(t_stack **stack);
int			min_data(t_stack **stack);
int			stack_size(t_stack **stack);
void		bring_top(t_stack **stack);

//Rules----------------------------------------/

// sa && sb
void		swap(t_stack **stack, char *msg);
void		ss(t_stack **stack_a, t_stack **stack_b);
// pa && pb
void		push_to_stack(t_stack **stack_a, t_stack **stack_b, char *msg);
// ra && rb
void		rotate(t_stack **stack_a, char *msg);
// rra rrb
void		rev_rot(t_stack **stack_a, char *msg);
// rr
void		rr(t_stack **stack_a, t_stack **stack_b);

//Errors -------------------------------------/

int			is_duplicate(t_stack **stack, int value);
int			is_valid_number(const char *str);
int			check_max(long int value);
void		ft_error(t_stack **stack_a, char **split);

//sort ---------------------------------------/
int			sort2(t_stack **stack);
int			sort3(t_stack **stack);
int			sort4(t_stack **stack_a, t_stack **stack_b);
int			sort5(t_stack **stack_a, t_stack **stack_b);
int			check_sort(t_stack **stack);
int			sort(t_stack **a, t_stack **b);
int			*sort_tab(t_stack **stack_a);
int			find_big(t_stack **stack);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		pre_sort(t_stack **stack_a, t_stack **stack_b, int range);
void		big_to_top(t_stack **stack_b);
void		big_sort(t_stack **stack_a, t_stack **stack_b);

#endif