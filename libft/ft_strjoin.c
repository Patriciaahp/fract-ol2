/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:54:20 by pahernan          #+#    #+#             */
/*   Updated: 2025/01/16 10:34:11 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	s3 = malloc(sizeof(char) * (i + j + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, i + 1);
	ft_strlcpy(s3 + i, s2, j + 1);
	return (s3);
}
