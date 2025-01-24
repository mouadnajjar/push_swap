/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:38:15 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/17 17:00:31 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sl;
	char	*substr;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (start >= sl)
		len = 0;
	else if (start + len > sl)
	{
		len = sl - start;
	}
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	while ((nptr[i] && nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = malloc(sizeof(ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while ((dest || src) && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
