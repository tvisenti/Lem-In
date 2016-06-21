/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:06:03 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/21 14:36:04 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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
		ft_printf("%s\n", line);
		if (line[0] == '#')
			li_sharp(line, lst);
		else if (li_room_tube(line, lst) == 0)
			return (0);
	}
	return (1);
}

int			main(void)
{
	char	*line;
	t_lem	*lst;

	line = NULL;
	lst = li_lstnew();
	if (li_parse(line, lst) < 0)
		li_error();
	if (li_algo(lst, lst->end) == 1)
		li_solve(lst);
	else
		ft_printf("Wrong path\n");
	return (0);
}
