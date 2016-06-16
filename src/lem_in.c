/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:06:03 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/16 15:21:31 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"
#include <stdio.h>

/*
** Debut du parseur de fichier
** Voir la gestion d'erreur, pas sur pour le return (0)
*/

int			li_parse(char *line, t_lem *lst)
{
	if (li_get_ants(line, lst) == 0)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		// ft_putstrn(line);
		if (line[0] == '#')
			li_sharp(line, lst);
		else if (li_room_tube(line, lst) == 0)
			return (0);
	}
	return (1);
}

int		main(void)
{
	char	*line;
	t_lem	*lst;

	lst = li_lstnew(lst);
	if (li_parse(line, lst) < 0)
		li_error();
	return (0);
}
