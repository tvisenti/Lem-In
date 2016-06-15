/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:39:27 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/15 18:36:47 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

int		li_is_exist(char *str, t_lem *lst)
{
	t_salle	*tmp;

	if (lst->start == NULL)
	{
		lst = li_lstadd(lst, str);
		return (1);
	}
	tmp = lst->start;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (0);
		tmp = tmp->next;
	}
	lst = li_lstadd(lst, str);
	return (1);
}

int		li_check_coord(char *str, char **tab, t_lem *lst)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	if (li_is_exist(tab[i], lst) == 0)
		return (0);
	x = ft_atoi(tab[++i]);
	y = ft_atoi(tab[++i]);
	if (x == -0 || y == -0)
		return (0);
	return (1);
}

t_salle		*li_make_link(t_lem *lst, t_salle *r1, t_salle *r2)
{
	int	i;
	t_salle **new;

	i = 0;
	if (!r1->tube)
	{
		r1->tube = malloc(sizeof(t_salle*) * 2);
		r1->tube[0] = r2;
		r1->tube[1] = NULL;
	}
	else
	{
		while (r1->tube[i] != NULL)
			i++;
		new = malloc(sizeof(t_salle*) * i + 2);
		'fonction boucle qui copie r1->tube dans new'
		new[i] = r2;
		new[++i] = NULL;
	}
	return (r1);
}

t_salle	*li_find_elem(t_lem *lst, t_salle *elem, char *str)
{
	elem = lst->start;
	while (elem)
	{
		if (ft_strcmp(elem->name, str) == 0)
		{
			printf("salle : %s - str : %s\n", elem->name, str);
			return (elem);
		}
		elem = elem->next;
	}
	printf("salle : not found = %s\n", str);
	return (NULL);
}

int		li_room_tube(char *line, t_lem *lst)
{
	char	**tab;
	t_salle	*r1;
	t_salle	*r2;

	if (ft_strnlen(line, '-') > 0)
	{
		tab = ft_strsplit(line, '-');
		r1 = li_find_elem(lst, r1, tab[0]);
		r2 = li_find_elem(lst, r2, tab[1]);
		free(tab);
		if (!r1 || !r2)
		{
			printf("INVALID\n");
			return (0);
		}
		lst->begin_tube = 1;
		r1 = li_make_link(lst, r1, r2);
		r2 = li_make_link(lst, r2, r1);
		printf("VALID\n");
		return (1);
	}
	else if (ft_strnlen(line, ' ') + 1 > 0 && lst->begin_tube == 0)
	{
		tab = ft_strsplit(line, ' ');
		li_check_coord(line, tab, lst);
		free(tab);
		return (1);
	}
	return (0);
}

int		li_start_end(char *line, t_lem *lst, int start)
{
	int		i;
	char	**tab;

	i = 0;
	get_next_line(0, &line);
	// ft_putstrn(line);
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	tab = ft_strsplit(line, ' ');
	if (start == 1)
		lst->name_start = ft_strdup(tab[0]);
	else if (start == 2)
		lst->name_end = ft_strdup(tab[0]);
	if (li_check_coord(line, tab, lst) == 0)
	{
		free(tab);
		return (0);
	}
	free(tab);
	return (1);
}

int		li_sharp(char *line, t_lem *lst)
{
	if (ft_strcmp("##start", line) == 0)
	{
		if (lst->name_start != NULL || li_start_end(line, lst, 1) == 0)
			return (0);
		printf("OK start\n");
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		if (lst->name_end != NULL || li_start_end(line, lst, 2) == 0)
			return (0);
		printf("OK end\n");
	}
	return (1);
}

int		li_get_ants(char *line, t_lem *lst)
{
	int	nb;

	get_next_line(0, &line);
	ft_putstrn(line);
	nb = ft_atoi(line);
	if (nb == -0 || nb < 0)
		return (0);
	lst->ants = nb;
	return (1);
}

int		li_parse(char *line, t_lem *lst)
{
	int	i = 0;
	if (li_get_ants(line, lst) == 0)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		// ft_putstrn(line);
		if (line[0] == '#')
			li_sharp(line, lst);
		else if (li_room_tube(line, lst) == 0)
			i = 1;
	}
	return (1);
}
