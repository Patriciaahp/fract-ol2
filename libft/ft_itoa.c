/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:06:39 by pahernan          #+#    #+#             */
/*   Updated: 2025/07/16 20:20:27 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_strnum(char *s, int *i, int n)
{
	while (*i > 0)
	{
		if (s[0] == '-')
		{
			s[(*i)-- - 1] = (n % 10) + '0';
			n /= 10;
			s[0] = '-';
		}
		else
		{
			s[(*i)-- - 1] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numlen(n);
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	j = i;
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	ft_strnum(s, &i, n);
	s[j] = '\0';
	return (s);
}
