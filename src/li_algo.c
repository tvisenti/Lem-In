/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:15:42 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/17 17:27:27 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

// t_salle	**li_realloc_f(t_lem *lst, t_salle **file, t_salle *elem)
// {
// 	int	i;
//
// 	i = 0;
// 	printf("SECOND\n");
// 	while (elem->tube[i])
// 		i++;
// 	file = malloc(sizeof(t_salle*) * i + 1);
// 	file[i++] = NULL;
// 	i = -1;
// 	while (elem->tube[++i])
// 		file[i] = elem->tube[i];
// 	return (file);
// }
//
// t_salle	**li_malloc_f(t_lem *lst, t_salle **file, t_salle *elem)
// {
// 	int	i;
//
// 	i = 0;
// 	printf("FIRST\n");
// 	printf("name of end : %s\n", elem->name);
// 	if (lst->end->tube[i] == NULL)
// 		return (NULL);
// 	while (elem->tube[i])
// 	{
// 		printf("name : %s\n", elem->tube[i]->name);
// 		i++;
// 	}
// 	printf("i = %d\n", i);
// 	file = malloc(sizeof(t_salle*) * i);
// 	file[i++] = NULL;
// 	i = -1;
// 	while (elem->tube[++i] != NULL)
// 	{
// 		file[i] = elem->tube[i];
// 		// printf("REALLOC : %s\n", file[i]->tube[i]->name);
// 	}
// 	return (file);
// }

int		li_recursive(t_lem *lst, t_salle *elem, int deep, int weight)
{
	int		i;
	int		loop;

	i = 0;
	loop = 0;
	printf("elem->name : %s\t", elem->name);
	printf("elem->poids : %d\n", elem->poids);
	if (deep < 0)
		return (1);
	while (elem != lst->start)
	{
		while (elem->tube[i])
		{
			if (elem->tube[i]->poids == INT_MAX)
				elem->tube[i]->poids = weight;

			i++;
		}
		loop++;
		if (loop < i)
			return (li_recursive(lst, elem->tube[loop], deep - 1, weight));
		i = 0;
	}
	return (0);
}

int		li_algo(t_lem *lst, t_salle *elem)
{
	int	deep;
	int	weigth;
	int	ret;
	int	i;

	i = 0;
	deep = 0;
	weigth = 0;
	ret = 1;
	while (elem->tube[i] && ret > 0)
	{
		ret = li_recursive(lst, elem->tube[i], deep, weigth);
		i++;
	}

	return (0);
}
