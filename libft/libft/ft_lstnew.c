/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:00 by pahernan          #+#    #+#             */
/*   Updated: 2025/01/17 13:11:20 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/*int	main(void)
{
	char	*str;

	t_list	*elem;
	str = (char *)malloc(6*sizeof(char));
	str = "Hola";
	elem = ft_lstnew((void *)str);
	printf("%s\n", (char *)elem->content);
	free(new->content);
}*/