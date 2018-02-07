/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:35:51 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:35:53 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && n > 0)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
		n--;
	}
	if ((char)c == '\0')
		return ((char*)&s[i]);
	return (0);
}
