/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:15:42 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/28 12:19:38 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Replace le start et le end par les bonnes salles
*/

void	li_replace_start_end(t_lem *lst)
{
	t_salle *start;
	t_salle *end;
	t_salle *tmp;

	tmp = lst->start;
	if (ft_strcmp(lst->start->name, lst->name_start) != 0)
	{
		while (ft_strcmp(tmp->next->name, lst->name_start) != 0)
			tmp = tmp->next;
		start = tmp->next;
		tmp->next = start->next;
		start->next = lst->start;
		lst->start = start;
		tmp = lst->start;
	}
	if (ft_strcmp(lst->end->name, lst->name_end) != 0)
	{
		while (ft_strcmp(tmp->next->name, lst->name_end) != 0)
			tmp = tmp->next;
		end = tmp->next;
		tmp->next = end->next;
		end->next = NULL;
		lst->end->next = end;
		lst->end = end;
	}
}

/*
** Attribue le poids à la salle
*/

int		li_put_weight(t_salle *elem, int weight)
{
	elem->poids = weight;
	return (0);
}

/*
** u = -1 : salle déjà faite
** ret = 1 : arrive à start
** ret 0 : continue
*/

int		li_return_path(int ret, int u)
{
	if (u == -1)
		return (-1);
	if (ret == 1)
		return (1);
	return (0);
}

/*
** Descends à la bonne profondeur, check si la salle est
** déjà faite dans la recursive
*/

int		li_recursive(t_lem *lst, t_salle *elem, int deep, int weight)
{
	int		i;
	int		u;
	int		ret;

	i = 0;
	ret = 0;
	u = -1;
	if (elem->poids != INT_MAX && deep == 0)
		return (-1);
	if (elem == lst->start)
		return (1);
	if (elem->poids == INT_MAX)
		return (li_put_weight(elem, weight));
	while (elem->tube[i] != NULL && ret != 1)
	{
		ret = li_recursive(lst, elem->tube[i], deep - 1, weight);
		if (u == -1)
			u = ret;
		i++;
	}
	return (li_return_path(ret, u));
}

/*
** Boucle sur la recursive, envoi end a chaque tour et une
** profondeur + poids supérieur
*/

int		li_algo(t_lem *lst, t_salle *elem)
{
	int	deep;
	int	ret;

	if (lst->error == 1 || elem->tube == NULL)
		return (0);
	deep = 1;
	ret = 1;
	elem->poids = 0;
	while (!(ret = li_recursive(lst, elem, deep, deep)))
		deep++;
	if (ret == -1)
		return (0);
	return (1);
}
