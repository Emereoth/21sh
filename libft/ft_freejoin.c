/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:30:46 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:30:47 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char const *s1, char const *s2)
{
	char	*x;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup((char*)s1));
	if (!s1)
		return (ft_strdup((char*)s2));
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(x = (char*)malloc(sizeof(char) * j)))
		return (NULL);
	ft_strcpy(x, s1);
	ft_strcat(x, s2);
	free((char *)s1);
	return (x);
}
