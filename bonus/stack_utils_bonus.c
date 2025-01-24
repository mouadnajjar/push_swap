/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:39:42 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 17:09:46 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_stack(t_stack **stack)
{
	(*stack) = malloc(sizeof(t_stack));
	if (!(*stack))
		return ;
	(*stack)->top = NULL;
}

void	push(t_stack **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = NULL;
	if ((*stack)->top == NULL)
	{
		(*stack)->top = new_node;
		return ;
	}
	temp = (*stack)->top;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

int	is_empty(t_stack **stack)
{
	return ((*stack)->top == NULL);
}

void	free_stack(t_stack **stack)
{
	while (!is_empty(stack))
	{
		pop(stack);
	}
	free(*stack);
}
