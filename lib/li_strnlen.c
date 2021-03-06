/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 09:19:41 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/10 18:33:21 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_strnlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] != '\0')
		return (i);
	return (-1);
}
