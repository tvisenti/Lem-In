/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:15:42 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/20 21:00:03 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

int		li_put_weight(t_salle *elem, int weight)
{
	elem->poids = weight;
	printf("2 elem->name[i] : %s\t", elem->name);
	printf("elem->poids[i] : %d\n", elem->poids);
	return (0);
}

int		li_return_path(int ret, int u)
{
	if (u == -1)
	{
		printf("-----------\n");
		return (-1);
	}
	if (ret == 1)
	{
		printf("11111\n");
		return (1);
	}
	printf("000000\n");
	return (0);
}

// check si la salle est deja faite dans la recursive, ajout d'un int dans le .h

int		li_recursive(t_lem *lst, t_salle *elem, int deep, int weight)
{
	int		i;
	int		u;
	int		ret;

	i = 0;
	ret = 0;
	u = -1;
	printf("elem->name : %s\n", elem->name);
	printf("elem->poids : %d\n", elem->poids);
	if (elem->poids != INT_MAX && deep == 0)
		return (-1);
	if (elem == lst->start)
		return (1);
	if (elem->poids == INT_MAX)
		return (li_put_weight(elem, weight));
	while (elem->tube[i] != NULL && ret != 1)
	{
		printf("LOOP\n");
			ret = li_recursive(lst, elem->tube[i], deep - 1, weight);
			if (u == -1)
				u = ret;
		i++;
	}
	printf("NON PAS LA\n");
	return (li_return_path(ret, u));
}

int		li_algo(t_lem *lst, t_salle *elem)
{
	int	deep;
	int	ret;
	int	i;

	deep = 1;
	ret = 1;
	elem->poids = 0;
	printf("end->name : %s\n", elem->name);
	while (!(ret = li_recursive(lst, elem, deep, deep)))
		deep++;
	if (ret == -1)
		return (0);
	return (1);
}
