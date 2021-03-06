/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:19:42 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:19:43 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "shell.h"
#include "env.h"
#include "exec.h"

t_shell		*g_shell;

static int		recup_opt(char **argv, int i, int j, t_option *comp)
{
	if (argv[i][j] == 'i')
		comp->opt_i = 1;
	else if (argv[i][j] == 'u')
		comp->opt_u = 1;
	else if (argv[i][j] == 'v')
		comp->opt_v = 1;
	else
	{
		ft_putstr("env: illegal option -- ");
		ft_putchar(argv[i][j]);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

int				exec_opt_uv(char **argv, t_option comp, int i, t_detail *node)
{
	if (comp.opt_u)
	{
		if (!argv[2])
		{
			ft_putendl("env: option requires an argument -- u");
			free_detail(node);
			return (1);
		}
		option_u(&argv[1]);
		show_env();
		return (0);
	}
	if (comp.opt_v)
	{
		if (!argv[2])
		{
			show_env();
			return (0);
		}
		option_v(argv, node, i);
	}
	return (0);
}

int				exec_env(char **argv, t_option comp, int i)
{
	t_detail	*node;

	node = (t_detail *)ft_memalloc(sizeof(t_detail));
	if (ft_strstr(argv[i], "=") == NULL)
		no_option(argv, node, i);
	else if (ft_strstr(argv[i], "=") && ft_strncmp(argv[i], "=", 1) != 0)
	{
		show_env();
		while (argv[i])
		{
			ft_putendl(argv[i]);
			i++;
		}
	}
	else if (comp.opt_i)
		option_i(argv, node);
	else if (exec_opt_uv(argv, comp, i, node) == 1)
	{
		free_detail(node);
		return (1);
	}
	free_detail(node);
	return (0);
}

static int		env_option(char **argv, t_option *comp)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][0])
	{
		j = 1;
		if (!ft_strcmp(argv[i], "--"))
			return (1);
		if (argv[i][1] == '\0')
		{
			comp->opt_i = 1;
			return (0);
		}
		while (argv[i][j])
		{
			if (recup_opt(argv, i, j, comp) == 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

int				ft_env(char **argv)
{
	int			i;
	t_option	comp;
	int			j;

	i = ft_strstrlen(argv);
	if (i < 2)
		show_env();
	else
	{
		comp = (t_option) {0, 0, 0, 0, 0};
		if ((i = env_option(argv, &comp)) == -1)
			return (1);
		j = i - 1;
		while (argv[++j])
		{
			if (argv[j] && !ft_strstr(argv[j], "="))
			{
				exec_env(argv, comp, j);
				return (0);
			}
		}
		exec_env(argv, comp, i);
	}
	return (0);
}
