/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:47:46 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 17:43:30 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack **stack_a)
{
	t_node	*last;
	t_node	*tmp;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	last = (*stack_a)->top;
	while (last->next)
		last = last->next;
	tmp = (*stack_a)->top;
	(*stack_a)->top = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

void	rev_rot(t_stack **stack_a)
{
	t_node	*temp;
	t_node	*bf_last;

	if (!*stack_a || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->top;
	while (temp->next)
	{
		bf_last = temp;
		temp = temp->next;
	}
	bf_last->next = NULL;
	temp->next = (*stack_a)->top;
	(*stack_a)->top = temp;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	rev_rot(stack_a);
	rev_rot(stack_b);
}
