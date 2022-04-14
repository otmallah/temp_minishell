/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:58:25 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/29 10:58:26 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    add_to_temp_env(t_mini *index, t_idx *id, char *str)
{
	int		i;
	int		j;
	int		a;
	char	**temp;
	char	*temp2;

	i = id->a;
	j = 0;
	a = 0;
	temp = (char **)malloc(sizeof(char *) * id->b);
	while (i > 0)
	{
		temp2 = ft_substr(index->env_tab[j], 0, find_len3(index->env_tab[j]));
		if (ft_strcmp(temp2, str) == 0)
			j++;
		temp[a] = index->env_tab[j];
		j++;
		i--;
		a++;
	}
	index->env_tab = (char **)calloc(sizeof(char *) , (id->b + 1));
	i = id->a;
	j = 0;
	while (i > 0)
	{
		index->env_tab[j] = temp[j];
		j++;
		i--;
	}
	free(temp);
	index->env_tab[j] = NULL;
}

void    add_to_temp_expo(t_mini *index, t_idx *id, char *str)
{
	int		i;
	int		j;
	int		a;
	char	**temp;
	char	*temp2;

	i = id->d;
	j = 0;
	a = 0;
	temp = (char **)malloc(sizeof(char *) * id->c);
	while (i > 0)
	{
		if (ft_strcmp(index->tab_e[j], str) == 0)
			j++;
		temp[a] = index->tab_e[j];
		j++;
		i--;
		a++;
	}
	index->tab_e = (char **)calloc(sizeof(char *) , (id->c + 1));
	i = id->d;
	j = 0;
	while (i > 0)
	{
		index->tab_e[j] = temp[j];
		j++;
		i--;
	}
	free(temp);
	index->tab_e[j] = NULL;
}
