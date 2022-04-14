/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:35:08 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/18 20:35:09 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*st;

	st = (char *)str;
	i = 0;
	while (st[i])
	{
		if (st[i] == (char)c)
			return (st + i);
		i++;
	}
	if (st[i] == (char)c)
		return (st + i);
	return (NULL);
}
