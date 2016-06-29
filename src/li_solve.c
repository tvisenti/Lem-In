/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:52:32 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/29 13:22:06 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Verifie si il y a qu'un end et un start et si ils sont à replacer
*/

void		li_check_error(t_lem *lst)
{
	if (lst->start_end != 2)
		lst->error = 1;
	if (lst->error == 0 && (ft_strcmp(lst->end->name, lst->name_end) != 0 ||
	ft_strcmp(lst->start->name, lst->name_start) != 0))
		li_replace_start_end(lst);
}

/*
** Renvoi à la prochaine salle
*/

t_salle		*li_find_room(t_salle *elem)
{
	int		i;
	t_salle	*new;

	i = 1;
	if (elem->tube == NULL)
		return (NULL);
	new = elem->tube[0];
	while (elem->tube[i] != NULL)
	{
		if (new->poids > elem->tube[i]->poids)
			new = elem->tube[i];
		i++;
	}
	return (new);
}

/*
** Affiche le déplacement, ajout de la fourmie dans end si elle est arrivée
*/

t_salle		*li_affichage(t_salle *new, int ants, t_lem *lst)
{
	new = li_find_room(new);
	new->number++;
	if (new->number <= ants)
		ft_printf("L%d-%s ", new->number, new->name);
	if (new == lst->end)
		lst->end->ants++;
	return (new);
}

/*
** Boucle tant que les fourmis ne sont pas arrivées
*/

int			li_solve(t_lem *lst)
{
	int		i;
	int		ants;
	t_salle	*new;

	i = 1;
	new = lst->start;
	lst->start->here = 1;
	ants = lst->ants;
	lst->start->ants = ants;
	while (lst->end->ants != ants || lst->start->here != 0)
	{
		while (new != lst->end && new->next->here != 0)
			new = li_affichage(new, ants, lst);
		if (new != lst->end)
			new->next->here = 1;
		if (lst->ants > 0)
			lst->ants--;
		else
			lst->start->here = 0;
		new = lst->start;
		ft_printf("\n");
	}
	return (1);
}
