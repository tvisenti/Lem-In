/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 12:00:31 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/29 13:21:52 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

static void	li_add(t_salle *new, char *str)
{
	new->next = NULL;
	new->tube = NULL;
	new->ants = 0;
	new->number = 0;
	new->here = 0;
	new->poids = INT_MAX;
	new->name = ft_strdup(str);
}

t_lem		*li_lstadd(t_lem *lst, char *str)
{
	t_salle	*new;

	if (lst != NULL)
	{
		if ((new = (t_salle*)malloc(sizeof(t_salle))) != NULL)
		{
			li_add(new, str);
			if (lst->end == NULL)
			{
				lst->start = new;
				lst->end = new;
			}
			else
			{
				lst->end->next = new;
				lst->end = new;
			}
		}
	}
	return (lst);
}
