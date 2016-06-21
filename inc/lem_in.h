/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:06:51 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/21 13:24:26 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

# define INT_MAX 2147483647

typedef struct		s_salle
{
	int				poids;
	int				ants;
	char			*name;
	struct s_salle	*next;
	struct s_salle	**tube;
}					t_salle;

typedef struct		s_lem
{
	int				ants;
	int				begin_tube;
	char			*name_start;
	char			*name_end;
	struct s_salle	*start;
	struct s_salle	*end;
}					t_lem;

/*
** Les fonctions de la librairie
*/

void				li_error(void);
t_lem				*li_lstadd(t_lem *lst, char *str);
t_lem				*li_lstnew(void);
int					ft_strnlen(char *str, char c);

/*
** li_parse.c
*/

t_salle				**li_realloc(t_salle **new, t_salle *r1, t_salle *r2);
t_salle				**li_make_link(t_salle *r1, t_salle *r2);
t_salle				*li_find_elem(t_lem *lst, t_salle *elem, char *str);
int					li_room_tube(char *line, t_lem *lst);
int					li_is_exist(char *str, t_lem *lst);

/*
** li_make_link.c
*/

int					li_check_coord(char **tab, t_lem *lst);
int					li_get_start_end(char *line, t_lem *lst, int start);
int					li_sharp(char *line, t_lem *lst);
int					li_get_ants(char *line, t_lem *lst);
int					li_parse(char *line, t_lem *lst);

/*
** li_algo.c
*/

int					li_recursive(t_lem *lst, t_salle *elem, int deep,
	int weight);
int					li_put_weight(t_salle *elem, int weight);
int					li_return_path(int ret, int u);
int					li_algo(t_lem *lst, t_salle *elem);

/*
** li_solve.c
*/

t_salle				*li_find_room(t_lem *lst, t_salle *elem);
int					li_solve(t_lem *lst);

#endif
