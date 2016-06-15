/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:06:03 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/10 09:40:41 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"
#include <stdio.h>

int		main(void)
{
	char	*line;
	t_lem	*lst;

	lst = li_lstnew(lst);
	if (li_parse(line, lst) < 0)
		li_error();
	return (0);
}
