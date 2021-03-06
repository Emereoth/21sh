/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:24:16 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 14:31:44 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex_par_ast.h"
#include "exec.h"
#include "split.h"

/*
** Verifie la syntaxe des maillons de la liste principale
** (alternance cmd / sep, pas de '&& ou '||' a la fin)
*/

static t_lex	*check_sep_syntax(t_lex *lex)
{
	t_lex	*error;

	if (!lex)
		return (NULL);
	if (!lex->lst)
	{
		if ((ft_strcmp(lex->str, ";") && !lex->next))
			return (sep_pars_error(lex, 0));
		if ((lex->prev && !lex->prev->lst) || (lex->next && !lex->next->lst))
			return (sep_pars_error(lex, 1));
		if (!lex->prev
				&& (ft_strcmp(lex->str, "&&") || ft_strcmp(lex->str, "||")))
			return (sep_pars_error(lex, 1));
		if (pars_next_sep(lex) == lex->next)
			return (sep_pars_error(lex, 1));
	}
	if ((error = check_sep_syntax(pars_next_sep(lex))))
		return (error);
	return (NULL);
}

/*
** Appel en cas d'erreur de syntaxe, free toutes les listes
*/

static t_lex	*free_all(t_lex *main_lst)
{
	t_lex		*main_tmp;

	while (main_lst)
	{
		ft_strdel(&main_lst->str);
		free_detail(main_lst->lst);
		main_tmp = main_lst->next;
		free(main_lst);
		main_lst = main_tmp;
	}
	return (NULL);
}

/*
** Retourne un int correspondant au symbole de redirection
** d'un maillon comprenant une redirection (parcours recursif)
*/

static void		assign_redir(t_detail *link, char *file, t_detail **error)
{
	int		i;

	i = -1;
	if (!link)
		return ;
	while (link->redir_str && link->redir_str[++i])
	{
		if (ft_strstr(link->redir_str[i], ">>"))
			link->redir[i] = DB_R;
		else if (ft_strstr(link->redir_str[i], "<<"))
		{
			link->redir[i] = DB_L;
			file = get_file(link->redir_str[i]);
			if (heredoc(link, DB_L, file, i))
				*error = link;
		}
		else if (ft_strstr(link->redir_str[i], ">"))
			link->redir[i] = S_R;
		else if (ft_strstr(link->redir_str[i], "<"))
			link->redir[i] = S_L;
		else
			link->redir[i] = -1;
		ft_strdel(&file);
	}
	!error ? assign_redir(link->next, NULL, error) : 0;
}

/*
** Verifie le positionnement des tokens selon leur type (parcours recursif)
*/

static t_detail	*check_cmd_syntax(t_detail *link)
{
	t_detail	*error;

	if (!link)
		return (NULL);
	if (link->redir_str && check_redir_tab(link->redir_str))
		return (cmd_pars_error(link, 4));
	if (link->pipe && (!link->next || (link->next && !link->next->argv)
				|| !link->argv))
		return (cmd_pars_error(link, 5));
	if ((error = check_cmd_syntax(link->next)))
		return (error);
	return (NULL);
}

/*
** Assigne le type des tokens et verifie leur placement
** Appelle la fonction de creation des sous-listes, donne leurs types aux
** maillons et aux redirs des sous-listes
*/

t_lex			*parser(t_lex *lex)
{
	t_lex		*cursor;
	t_detail	*det_error;
	t_lex		*sep_error;

	cursor = lex;
	det_error = NULL;
	sep_error = NULL;
	while (cursor && !det_error)
	{
		if (!is_sep(cursor->str))
		{
			if ((cursor->lst = str_to_lst(cursor->str)) == NULL)
				return (free_all(lex));
			det_error = check_cmd_syntax(cursor->lst);
			if (!det_error)
				assign_redir(cursor->lst, NULL, &det_error);
		}
		else
			cursor->lst = NULL;
		cursor = cursor->next;
	}
	if (det_error)
		return (free_all(lex));
	sep_error = check_sep_syntax(lex);
	return (sep_error ? free_all(lex) : lex);
}
