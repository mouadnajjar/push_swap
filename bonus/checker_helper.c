/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:14:45 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 17:42:54 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	valid_operations(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(op, "pa\n") == 0)
		push_to_stack(stack_b, stack_a);
	else if (ft_strcmp(op, "pb\n") == 0)
		push_to_stack(stack_a, stack_b);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rev_rot(stack_a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rev_rot(stack_b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}
