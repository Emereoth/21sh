/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:26:17 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:26:19 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int rslt;
	int i;
	int sign;

	rslt = 0;
	i = 0;
	sign = 1;
	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		rslt = rslt * 10 + str[i] - '0';
		i++;
	}
	return (rslt * sign);
}
