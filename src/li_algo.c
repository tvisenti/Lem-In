/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:15:42 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/20 14:44:19 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

int		li_put_weight(t_lem *lst, t_salle *elem, int i, int weight)
{
	if (elem->tube[i]->poids == INT_MAX)
	{
		elem->tube[i]->poids = weight;
		printf("2 elem->name[i] : %s\t", elem->tube[i]->name);
		printf("elem->poids[i] : %d\n", elem->tube[i]->poids);
		return (1);
	}
	return (0);
}

int		li_recursive(t_lem *lst, t_salle *elem, int deep, int weight)
{
	int		i;
	int		ret;

	i = 0;
	printf("elem->name : %s\n", elem->name);
	if (elem == lst->start)
	{
		printf("FIN elem == lst->start\n");
		return (1);
	}
	if (deep == 0)
	{
		printf("FIN deep == 0\n");
		return (li_put_weight(lst, elem, i, weight));
	}
	while (elem != lst->start && elem->tube[i] != NULL)
	{
		printf("LOOP\n");
			ret = li_recursive(lst, elem->tube[i], deep - 1, weight);
			i++;
	}
	printf("Je suis sur le start !!!!\n");
	return (1);
}

int		li_algo(t_lem *lst, t_salle *elem)
{
	int	deep;
	int	weigth;
	int	ret;
	int	i;

	i = 0;
	deep = 0;
	weigth = 0;
	ret = 1;
	printf("end->name : %s\n", elem->name);
	elem->poids = 0;
	while (elem->tube[i] != NULL && ret > 0)
	{
		printf("FIRST TOUR\n");
		ret = li_recursive(lst, elem->tube[i], deep + 1, weigth + 1);
		i++;
	}

	return (0);
}
