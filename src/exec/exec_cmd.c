/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:42 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:44 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "env.h"
#include "lex_par_ast.h"
#include "builtin.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

t_shell			*g_shell;

char				*find_bin(char *arg, int error)
{
	char			*bin;
	char			*temp;
	struct stat		statvar;

	bin = (ft_isin(arg, '/') ? ft_strdup(arg) : give_path(arg, g_shell->table));
	if (!arg)
		return (NULL);
	if (!bin)
	{
		bin = toexec(arg);
		if (bin)
		{
			temp = ft_strsub(bin, 0, ft_strlen(bin) - ft_strlen(arg) - 1);
			add_hash_to_tab(arg, temp);
			free(temp);
		}
	}
	if ((!bin || stat(bin, &statvar) == -1) && error)
		return (error_message(127, arg));
	if (bin && access(bin, X_OK) == -1)
	{
		free(bin);
		return (error ? error_message(126, arg) : NULL);
	}
	return (bin);
}

void				exec_basic_cmd(t_detail *node, char **env)
{
	char		*bin;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
	if (node->argv && (bin = find_bin(*(node->argv), 1)))
	{
		linkio(node);
		execve(bin, node->argv, env);
	}
	exit(1);
}

void				exec_pipe(t_detail *node, char **env)
{
	int			pfd[2];
	pid_t		pid;
	int			status;

	pipe(pfd);
	if ((pid = fork()) == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		exec_basic_cmd(node, env);
	}
	else
	{
		if (!find_bin(node->argv[0], 0))
			waitpid(pid, &status, WUNTRACED);
		close(pfd[1]);
		dup2(pfd[0], STDIN_FILENO);
		if (node->next->next)
			exec_pipe(node->next, env);
		exec_basic_cmd(node->next, env);
	}
}

int					exec_cmd(t_node *tree, char **env)
{
	pid_t		pid;
	int			status;
	char		*temp;

	status = 0;
	if (tree->lst && tree->lst->argv
			&& (temp = find_bin(*(tree->lst->argv), 0)))
		free(temp);
	if ((pid = fork()) == 0)
	{
		if (tree && tree->lst && tree->lst->pipe)
			exec_pipe(tree->lst, env);
		else if (tree && tree->lst)
			exec_basic_cmd(tree->lst, env);
		exit(1);
	}
	else
	{
		dup2(tree->in, STDIN_FILENO);
		dup2(tree->out, STDOUT_FILENO);
		dup2(tree->err, STDERR_FILENO);
		waitpid(pid, &status, WUNTRACED);
	}
	return (status);
}

int					prep_exec(t_node *tree, char **env)
{
	int			status;

	if (!tree || !tree->lst)
		return (0);
	if (select_redir(tree))
		return (1);
	if (tree->lst && !tree->lst->next
			&& (status = builtin(tree->lst)) != -1)
	{
		dup2(tree->in, STDIN_FILENO);
		dup2(tree->out, STDOUT_FILENO);
		dup2(tree->err, STDERR_FILENO);
		return (status);
	}
	status = 0;
	status = exec_cmd(tree, env);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WIFSIGNALED(status) ? WTERMSIG(status) : status);
}
