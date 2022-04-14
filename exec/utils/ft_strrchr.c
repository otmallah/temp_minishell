/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:59:44 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/23 18:59:45 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*st;
	int		i;

	st = (char *)str;
	i = ft_strlen(st);
	while (i >= 0)
	{
		if (st[i] == (unsigned char)c)
        {
            i--;
			return (st + i);
        }
        i--;
	}
	return (NULL);
}
