/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob2ez.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:24:41 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:24:43 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int		get_pass(char ***argv, int i, char **tp, char **temp3)
{
	char	*match;
	int		ret;

	ret = 1;
	*tp = ft_strdup((*argv)[i]);
	*temp3 = *tp;
	if (need_glob_str((*argv)[i]))
	{
		if (!ft_strchr((*argv)[i], '/'))
			match = ft_strdup((*argv)[i]);
		else
			match = ft_strndup((*argv)[i], ft_strlen((*argv)[i]) -
					ft_strlen(ft_strchr((*argv)[i], '/')));
		*argv = ft_strstrjoin(*argv,
				glob_get_files(NULL, match, ft_strchr((*argv)[i], '/'), &ret));
		free(match);
	}
	return (ret);
}

char	*trace_road(char ***argv, char *tp, int *ret, int i)
{
	char	*match;
	char	*previous;
	char	*after;

	after = NULL;
	previous = ft_strndup((*argv)[i], ft_strlen((*argv)[i]) - ft_strlen(tp));
	if (previous && ft_strcmp(previous, "") == 0)
	{
		free(previous);
		previous = ft_strdup("/");
	}
	match = (!ft_strchr(tp + 1, '/') ? ft_strdup(tp + 1) :
			ft_strndup(tp + 1, ft_strlen(tp + 1) -
				ft_strlen(ft_strchr(tp + 1, '/'))));
	after = (!ft_strchr(tp + 1, '/') ? NULL :
			ft_strdup(ft_strchr(tp + 1, '/')));
	*argv = ft_strstrjoin(*argv,
			glob_get_files(previous, match, after, ret));
	free(match);
	free(previous);
	return (after);
}
