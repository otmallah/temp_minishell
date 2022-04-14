/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:18:59 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/18 16:19:01 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	size(const char	*s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
			i--;
		}
		i++;
	}
	return (j);
}

static void	check_p(char *st, int num, char sep, char **tab)
{
	int	start;
	int	b;
	int	i;

	i = 0;
	start = 0;
	b = 0;
	while (i < num)
	{
		while (st[b] == sep)
			b++;
		start = b;
		while (st[b] != sep && st[b])
			b++;
		tab[i] = ft_substr(st, start, (b - start));
		i++;
	}
	tab[i] = NULL;
}

char	**ft_split(char *s, char l)
{
	char	**tab;
	int		num_str;

	if (!s)
		return (NULL);
	num_str = size(s, l);
	tab = (char **)malloc(sizeof(char *) * (num_str + 2));
	if (!tab)
		return (NULL);
	check_p(s, num_str, l, tab);
	return (tab);
}