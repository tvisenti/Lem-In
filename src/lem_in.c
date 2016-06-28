/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:26:51 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/27 17:57:53 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Debut du parseur de fichier
*/

int			li_parse(char *line, t_lem *lst)
{
	li_get_ants(line, lst);
	while (get_next_line(0, &line) > 0 && lst->error == 0)
	{
		ft_printf("%s\n", line);
		if (line[0] == '#')
			li_sharp(line, lst);
		else if (li_room_tube(line, lst) == 0)
			lst->error = 1;
	}
	if (lst->error == 1)
		ft_printf("%s\n", line);
	while (lst->error == 1 && get_next_line(0, &line) > 0)
		ft_printf("%s\n", line);
	if (lst->tube == 0)
		lst->error = 1;
	return (1);
}

int			main(void)
{
	char	*line;
	t_lem	*lst;

	line = NULL;
	lst = li_lstnew();
	if (li_parse(line, lst) == 0 || lst->start_end != 2)
	{
		ft_printf("\nMerci de mettre un chemin valide.\n");
		return (0);
	}
	if (lst->error == 0 && li_algo(lst, lst->end) == 1)
	{
		ft_printf("\n");
		li_solve(lst);
	}
	else if (lst->error == 1 && lst->ants <= 0)
		ft_printf("\nLes fourmis sont parties dans une autre fourmilière.\n");
	else
		ft_printf("\nLes tubes ne relient pas start à end / aucune salle.\n");
	return (0);
}
