/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:51:27 by pahernan          #+#    #+#             */
/*   Updated: 2025/01/17 12:17:33 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i] && s[*i] != c)
	{
		len++;
		(*i)++;
	}
	return (len);
}

static int	ft_findwords(char const *s, char c, int *i, char **s3)
{
	int	k;
	int	l;

	k = 0;
	while (s[*i])
	{
		if (s[*i] == c)
			(*i)++;
		else
		{
			l = ft_wordlen(s, c, i);
			s3[k] = (char *)malloc(sizeof(char) * (l + 1));
			if (!s3[k])
			{
				while (k > 0)
					free(s3[k-- - 1]);
				free(s3);
				return (-1);
			}
			ft_strlcpy(s3[k], &s[*i - l], l + 1);
			k++;
		}
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		count;
	char	**s3;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	s3 = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s3)
		return (NULL);
	i = 0;
	k = ft_findwords(s, c, &i, s3);
	if (k == -1)
		return (NULL);
	s3[k] = NULL;
	return (s3);
}
