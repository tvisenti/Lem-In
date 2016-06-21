/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:52:32 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/21 11:30:18 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

t_salle	*li_find_room(t_lem *lst, t_salle *elem)
{
	int		i;
	t_salle *new;

	i = 0;
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
	return (new);
}

int		li_solve(t_lem *lst)
{
	t_salle *new;

	new = lst->start;
	printf("Start : %s\n", new->name);
	while (new != lst->end)
	{
		new = li_find_room(lst, new);
		printf("salle : %s\n", new->name);
	}
	return (1);
}
