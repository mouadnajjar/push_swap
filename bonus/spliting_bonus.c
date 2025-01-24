/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:47:38 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 16:24:11 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*string;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlenn(s1) + ft_strlenn(s2) + 1;
	string = (char *)malloc(len * sizeof(char) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = ' ';
	string[i + 1] = '\0';
	return (string);
}

static int	check_empty(char **av, int i)
{
	if (!av[i][0])
	{
		return (1);
	}
	return (0);
}

char	*get_args(int ac, char **av)
{
	char	*new;
	char	*tmp;
	int		i;

	if (ac < 2)
		return (NULL);
	new = ft_strdup("");
	i = 1;
	while (i < ac)
	{
		if (check_empty(av, i) == 1)
		{
			free (new);
			return (NULL);
		}
		tmp = ft_strjoin(new, av[i]);
		free (new);
		new = tmp;
		i += 1;
	}
	return (new);
}
