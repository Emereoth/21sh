/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:36:39 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:36:41 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strswitch(int c1, int c2, char *c)
{
	char	temp;

	temp = c[c1];
	c[c1] = c[c2];
	c[c2] = temp;
	return (c);
}
