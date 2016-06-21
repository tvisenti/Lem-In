/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:52:32 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/21 13:25:39 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_salle	*li_find_room(t_lem *lst, t_salle *elem)
{
	int		i;
	t_salle	*new;

	i = 0;
	new = elem;
	if (elem->tube[i] != NULL)
	{
		new = elem->tube[i];
		i++;
		while (elem->tube[i] != NULL)
		{
			if (new->poids > elem->tube[i]->poids)
				new = elem->tube[i];
			i++;
		}
	}
	if (new != lst->end)
		new->ants = 1;
	return (new);
}

int		li_solve(t_lem *lst)
{
	t_salle	*new;
	int		ants;
	int		i;

	i = 1;
	new = lst->start;
	ants = lst->ants;
	lst->start->ants = ants;
	printf("Ants : %d\n", lst->ants);
	printf("Start : %s\n", new->name);
	while (lst->end->ants != ants && lst->start->ants > 0)
	{
		if (lst->ants > 0)
			lst->ants--;
		lst->end->ants++;
		new = li_find_room(lst, new);
		printf("L%d-%s\n", i, new->name);
		i++;
	}
	return (1);
}
