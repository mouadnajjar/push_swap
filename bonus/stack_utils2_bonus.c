/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:15:04 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 17:28:48 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_size(t_stack **stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = (*stack)->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	check_sort(t_stack **stack)
{
	t_node	*current;

	if ((*stack)->top == NULL || (*stack)->top->next == NULL)
		return (1);
	current = (*stack)->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
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
