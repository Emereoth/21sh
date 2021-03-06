/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:32:17 by lvalenti          #+#    #+#             */
/*   Updated: 2017/04/03 18:32:18 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "lex_par_ast.h"

int					ft_strcmpset(char *str1, char *str2);
int					prep_exec(t_node *tree, char **env);
char				*error_message(int ret, char *cmd);
t_node				*walkthrough(t_node *tree);
int					select_redir(t_node *tree);
char				*get_file(char *str);
int					linkio(t_detail *node);
void				heredoc_assign(t_node *tree);
int					heredoc(t_detail *node, int type, char *end, int i);
void				exec_basic_cmd(t_detail *node, char **env);
void				free_detail(t_detail *node);

#endif
