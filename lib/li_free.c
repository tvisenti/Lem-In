/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:07:51 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/29 15:15:05 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		li_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int		li_free_salle(t_lem *lst)
{
	t_salle	*elem;
	t_salle	*tmp;

	elem = lst->start;
	while (elem)
	{
		tmp = elem->next;
		free(elem->name);
		free(elem);
		elem = tmp;
	}
	return (0);
}

int		li_free_lst(t_lem *lst)
{
	if (lst)
	{
		free(lst->name_start);
		free(lst->name_end);
		free(lst);
	}
	return (0);
}
