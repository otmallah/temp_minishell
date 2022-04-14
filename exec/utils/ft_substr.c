/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:38 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/18 16:26:41 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

static void	check(const char *s, char *su, int sta, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= sta && j < len)
		{
			su[j] = s[i];
			j++;
		}
		i++;
	}
	su[j] = '\0';
}


char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;
	char	*sub;

	i = 0;
	j = 0;
	a = len + 1;
	if (s == NULL)
		return (NULL);
	if (a > ft_strlen(s))
		a = ft_strlen((s) + 1);
	sub = (char *)malloc(sizeof(char) * a + 1);
	if (!sub)
		return (NULL);
	check(s, sub, start, len);
	return (sub);
}
