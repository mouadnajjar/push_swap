/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:15:04 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/17 17:46:39 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_stack **stack)
{
	if ((*stack)->top == NULL)
		return (0);
	return ((*stack)->top->data);
}

int	min_data(t_stack **stack)
{
	t_node	*current;
	int		lowest;
	int		position;
	int		index;

	current = (*stack)->top;
	lowest = current->data;
	position = 0;
	index = 0;
	while (current)
	{
		if (current->data < lowest)
		{
			lowest = current->data;
			position = index;
		}
		current = current->next;
		index++;
	}
	return (position);
}

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

void	bring_top(t_stack **stack)
{
	int	position;
	int	size;

	position = min_data(stack);
	size = stack_size(stack);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			rotate(stack, "ra\n");
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rev_rot(stack, "rra\n");
			position++;
		}
	}
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
