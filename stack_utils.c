/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:39:42 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/18 14:02:24 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	pop(t_stack **stack)
{
	int		value;
	t_node	*temp;

	if ((*stack)->top == NULL)
	{
		write(1, "stack underflow!", 16);
		return (0);
	}
	temp = (*stack)->top;
	value = temp->data;
	(*stack)->top = temp->next;
	free (temp);
	return (value);
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
