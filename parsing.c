/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:37:04 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/18 17:57:11 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	is_valid_number(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		str++;
		if (*str == '\0')
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_duplicate(t_stack **stack, int value)
{
	t_node	*current;

	current = (*stack)->top;
	while (current)
	{
		if (current->data == value)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	ft_error(t_stack **stack_a, char **split)
{
	free_split(split);
	free_stack(stack_a);
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

int	check_max(long int value)
{
	return (value < INT_MIN || value > INT_MAX);
}
