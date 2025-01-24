/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:49:00 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 17:07:36 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack)->top || !(*stack)->top->next)
		return ;
	first = (*stack)->top;
	second = (*stack)->top->next;
	first->next = second->next;
	second->next = first;
	(*stack)->top = second;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	swap(stack_a);
	swap(stack_b);
}

void	push_to_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*tmp;

	if ((*stack_a)->top == NULL)
		return ;
	tmp = (*stack_a)->top;
	(*stack_a)->top = tmp->next;
	tmp->next = (*stack_b)->top;
	(*stack_b)->top = tmp;
}
