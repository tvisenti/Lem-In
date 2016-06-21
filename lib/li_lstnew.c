/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:37:21 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/21 14:17:53 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_lem	*li_lstnew(void)
{
	t_lem	*new;

	if (!(new = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	if (new != NULL)
	{
		new->ants = 0;
		new->begin_tube = 0;
		new->name_start = NULL;
		new->name_end = NULL;
		new->start = NULL;
		new->end = NULL;
		new->prev = NULL;
	}
	return (new);
}
