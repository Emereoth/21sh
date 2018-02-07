/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:19:59 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:01 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "split.h"

char	**ft_shlvl(char **env)
{
	char	*line;
	int		i;
	char	*temp;

	if (!env)
	{
		env = ft_strstrnew(1);
		env[0] = "SHLVL=1";
		return (env);
	}
	if ((line = getenvline("SHLVL=")) == NULL)
	{
		env = ft_strstradd(ft_strdup("SHLVL=1"), env);
		return (env);
	}
	i = casenofor("SHLVL");
	free(env[i]);
	temp = ft_itoa(ft_atoi(line) + 1);
	env[i] = ft_strjoin("SHLVL=", temp);
	free(temp);
	free(line);
	return (env);
}
