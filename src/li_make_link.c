/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_make_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 15:06:14 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/17 12:09:27 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

/*
** Reinscrit dans le nouveau tableau les pointeurs
*/

t_salle		**li_realloc(t_salle **new, t_salle *r1, t_salle *r2)
{
	int		i;

	i = 0;
	while (r1->tube[i])
	{
		new[i] = r1->tube[i];
		i++;
	}
	new[i] = r2;
	new[++i] = NULL;
	return (new);
}

/*
** Creer un pointeur sur tube A -> B
*/

t_salle		**li_make_link(t_lem *lst, t_salle *r1, t_salle *r2)
{
	int		i;
	t_salle	**new;

	i = 0;
	if (!r1->tube)
	{
		r1->tube = malloc(sizeof(t_salle*) * 2);
		r1->tube[0] = r2;
		r1->tube[1] = NULL;
	}
	else
	{
		while (r1->tube[i] != NULL)
			i++;
		new = malloc(sizeof(t_salle*) * (i + 2));
		new = li_realloc(new, r1, r2);
		return (new);
	}
	return (r1->tube);
}

/*
** Le tube a une salle existante
*/

t_salle		*li_find_elem(t_lem *lst, t_salle *elem, char *str)
{
	elem = lst->start;
	while (elem)
	{
		if (ft_strcmp(elem->name, str) == 0)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

/*
** Verifie si le tube = 2 salles existantes et creer le lien
*/

int			li_find_make_link(t_lem *lst, t_salle *r1, t_salle *r2, char **tab)
{
	if (tab[2] != NULL)
		return (0);
	r1 = li_find_elem(lst, r1, tab[0]);
	r2 = li_find_elem(lst, r2, tab[1]);
	free(tab);
	if (!r1 || !r2)
		return (0);
	lst->begin_tube = 1;
	r1->tube = li_make_link(lst, r1, r2);
	r2->tube = li_make_link(lst, r2, r1);
	return (1);
}

/*
** Verifie si c'est une salle ou un tube
*/

int			li_room_tube(char *line, t_lem *lst)
{
	char	**tab;
	t_salle	*r1;
	t_salle	*r2;

	if (ft_strnlen(line, '-') > 0)
	{
		tab = ft_strsplit(line, '-');
		return (li_find_make_link(lst, r1, r2, tab));
	}
	else if (ft_strnlen(line, ' ') + 1 > 0 && lst->begin_tube == 0)
	{
		tab = ft_strsplit(line, ' ');
		if (tab[3] != NULL)
			return (0);
		li_check_coord(line, tab, lst);
		free(tab);
		return (1);
	}
	return (0);
}
