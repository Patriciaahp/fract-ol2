/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:08:54 by pahernan          #+#    #+#             */
/*   Updated: 2025/01/15 12:54:37 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

static int	ft_trimleft(const char *s, const char *set, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (set[j] && s[i] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	ft_trimright(const char *s, const char *set, int length,
int i)
{
	int	k;
	int	j;

	k = length - 1;
	while (k >= i)
	{
		j = 0;
		while (set[j] && s[k] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		k--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		k;
	int		length;
	int		l;

	if (!s1 || !set)
		return (NULL);
	length = ft_length(s1);
	i = ft_trimleft(s1, set, length);
	k = ft_trimright(s1, set, length, i);
	s2 = malloc(sizeof(char) * (k - i + 2));
	if (!s2)
		return (NULL);
	l = 0;
	while (i <= k)
		s2[l++] = s1[i++];
	s2[l] = '\0';
	return (s2);
}
