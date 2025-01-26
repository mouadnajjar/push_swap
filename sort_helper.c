/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:44:21 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/24 12:37:53 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_tab(t_stack **stack_a, int *tab)
{
	int		i;
	t_node	*current;

	current = (*stack_a)->top;
	i = 0;
	while (current)
	{
		tab[i++] = current->data;
		current = current->next;
	}
	return (tab);
}

int	*sort_tab(t_stack **stack_a)
{
	int		*tab;
	int		i;
	int		size;
	int		swap;

	i = 0;
	size = stack_size(stack_a);
	tab = malloc(sizeof(int) * size);
	tab = stack_to_tab(stack_a, tab);
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int	find_big(t_stack **stack)
{
	int		max;
	int		i;
	t_node	*tmp;
	t_node	*current;

	current = (*stack)->top;
	tmp = (*stack)->top;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	while (current)
	{
		if (current->data == max)
		{
			break ;
		}
		current = current->next;
		i++;
	}
	return (i);
}

void	big_to_top(t_stack **stack_b)
{
	int	i;

	while (1)
	{
		i = find_big(stack_b);
		if (i == 0)
			break ;
		else if (i <= stack_size(stack_b) / 2)
			rotate(stack_b, "rb\n");
		else
			rev_rot(stack_b, "rrb\n");
	}
}

void	pre_sort(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	*tab;
	int	i;
	int	size;

	i = 0;
	tab = sort_tab(stack_a);
	size = stack_size(stack_a);
	while ((*stack_a)->top)
	{
		if ((*stack_a)->top->data <= tab[i])
		{
			push_to_stack(stack_a, stack_b, "pb\n");
			rotate(stack_b, "rb\n");
			i++;
		}
		else if (range + i < size && (*stack_a)->top->data > tab[i]
			&& (*stack_a)->top->data <= tab[range + i])
		{
			push_to_stack(stack_a, stack_b, "pb\n");
			i++;
		}
		else
			rotate(stack_a, "ra\n");
	}
	free (tab);
}
