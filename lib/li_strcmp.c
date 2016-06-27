/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:28:51 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/27 16:00:10 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
#include "../libft/inc/libft.h"

int		li_strcmp(char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i] != s2[k] && s1[i] && s2[k])
		i++;
	while (s1[i] == s2[k] && s1[i] && s2[k])
	{
		i++;
		k++;
	}
	if (k == ft_strlen(s2))
		return (0);
	return (1);
}
