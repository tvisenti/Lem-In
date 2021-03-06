/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:37:21 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/27 12:10:17 by tvisenti         ###   ########.fr       */
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
		new->error = 0;
		new->tube = 0;
		new->begin_tube = 0;
		new->start_end = 0;
		new->name_start = NULL;
		new->name_end = NULL;
		new->start = NULL;
		new->end = NULL;
	}
	return (new);
}
