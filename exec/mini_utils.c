/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:36:49 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/03/13 09:18:23 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i++ < len1)
		p[i - 1] = s1[i - 1];
	while (i++ < len1 + len2 + 1)
		p[i - 2] = s2[i - len1 - 2];
	p[len1 + len2] = '\0';
	return (p);
}
