/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:15:42 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/21 14:37:43 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		li_put_weight(t_salle *elem, int weight)
{
	elem->poids = weight;
	return (0);
}

int		li_return_path(int ret, int u)
{
	if (u == -1)
		return (-1);
	if (ret == 1)
		return (1);
	return (0);
}

/*
** Check si la salle est deja faite dans la recursive, ajout d'un int dans le .h
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
		// if (lst->prev != elem->tube[i])
		// {
		// 	lst->prev = elem->tube[i];
			ret = li_recursive(lst, elem->tube[i], deep - 1, weight);
			if (u == -1)
				u = ret;
		// }
		i++;
	}
	return (li_return_path(ret, u));
}

int		li_algo(t_lem *lst, t_salle *elem)
{
	int	deep;
	int	ret;

	deep = 1;
	ret = 1;
	elem->poids = 0;
	while (!(ret = li_recursive(lst, elem, deep, deep)))
		deep++;
	if (ret == -1)
		return (0);
	return (1);
}
