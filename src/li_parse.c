/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:39:27 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/28 10:43:42 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Check si le maillon existe deja
*/

int			li_is_exist(char *str, t_lem *lst)
{
	t_salle	*tmp;

	if (lst->start == NULL)
	{
		lst = li_lstadd(lst, str);
		return (1);
	}
	tmp = lst->start;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
		{
			lst->error = 1;
			return (0);
		}
		tmp = tmp->next;
	}
	lst = li_lstadd(lst, str);
	return (1);
}

/*
** Verifie si la coordonnée est correcte
*/

int			li_check_coord(char **tab, t_lem *lst)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (li_is_exist(tab[i], lst) == 0)
		return (0);
	x = ft_atoi(tab[++i]);
	y = ft_atoi(tab[++i]);
	if (x < 0 || y < 0)
		lst->error = 1;
	return (1);
}

/*
** Sauvegarde le nom de l'entrée et sortie de la fourmiliere
*/

int			li_get_start_end(char *line, t_lem *lst, int start)
{
	int		i;
	char	**tab;

	i = 0;
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	tab = ft_strsplit(line, ' ');
	if (tab && tab[1] == NULL)
		return (0);
	if (start == 1)
		lst->name_start = ft_strdup(tab[0]);
	else if (start == 2)
		lst->name_end = ft_strdup(tab[0]);
	if (li_check_coord(tab, lst) == 0 || tab[3] != NULL)
	{
		free(tab);
		return (0);
	}
	free(tab);
	return (1);
}

/*
** Check si start ou end
*/

int			li_sharp(char *line, t_lem *lst)
{
	if (ft_strcmp("##start", line) == 0 && ft_strlen(line) == 7)
	{
		if (lst->name_start != NULL || li_get_start_end(line, lst, 1) == 0)
		{
			lst->error = 1;
			return (0);
		}
		lst->start_end++;
	}
	else if (ft_strcmp("##end", line) == 0 && ft_strlen(line) == 5)
	{
		if (lst->name_end != NULL || li_get_start_end(line, lst, 2) == 0)
		{
			lst->error = 1;
			return (0);
		}
		lst->start_end++;
	}
	return (1);
}

/*
** Recupere le nombre de fourmis
*/

int			li_get_ants(char *line, t_lem *lst)
{
	int		nb;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	nb = ft_atoi(line);
	if (nb <= 0)
	{
		lst->error = 1;
		lst->ants = nb;
		return (0);
	}
	lst->ants = nb;
	return (1);
}
