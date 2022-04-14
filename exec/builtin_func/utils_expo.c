/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:59:00 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/14 01:04:54 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_value(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return 1;
		i++;
	}
	return 0;
}

int find_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return i;
		i++;
	}
	return 0;
}

int	find_dup(t_mini *index, t_idx *id, char *find)
{
	int i;
	int j = 0;
	char *str;
	char *str2;

	i = id->a;
	while (i >= 0)
	{
		str = ft_substr(find, 0, find_len(find));
		str2 = ft_substr(index->env_tab[j], 0, find_len(index->env_tab[j]));
		if (ft_strcmp(str, str2) == 0)
		{
			str = ft_strrchr(find, '=');
			str2 = ft_strrchr(index->env_tab[j], '=');
			if (ft_strcmp(str, str2) == 0)
				return 0;
			else
			{
				index->env_tab[j] = find;
				return 1;
			}
		}
		i--;
		j++;
	}
	return 2;
}

int find_len3(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return i;
		i++;
	}
	return 0;
}

void	add_to_temp(t_mini *index, t_idx *id)
{
	int i;
	int j;
	char **temp;

	i = id->a;
	j = 0;
	temp = (char **)malloc(sizeof(char *) * id->b);
	while (i >= 0)
	{
		temp[j] = index->env_tab[j];
		j++;
		i--;
	}
	index->env_tab = (char **)malloc(sizeof(char *) * (id->b + 1));
	i = id->a;
	j = 0;
	while (i >= 0)
	{
		index->env_tab[j] = temp[j];
		j++;
		i--;
	}
	free(temp);
	index->env_tab[j] = NULL;
}

int	find_duplicate(t_mini *index, char *str,t_idx *id)
{
	int i;
	int j;
	int a;
	char *temp;
	char *str2;

	i = id->d;
	a = 0;
	j = 0;
	while (i >= 0)
	{
		a = find_value(str);
		if (a == 1)
		{
			temp = ft_substr(str, 0, find_len(str));
			str2 = ft_substr(index->tab_e[j], 0, find_len(index->tab_e[j]));
			if (ft_strcmp(temp, str2) == 0)
			{
				index->tab_e[j] = str;
				return 1;
			}
		}
		if (ft_strcmp(index->tab_e[j], str) == 0)
		{
			return 1;
		}
		i--;
		j++;
	}
	return 0;
}

void	add_to_temp2(t_mini *index, t_idx *id)
{
	int i;
	int j;
	char **temp;

	i = id->d;
	j = 0;
	temp = (char **)malloc(sizeof(char *) * id->c);
	while (i >= 0)
	{
		temp[j] = index->tab_e[j];
		j++;
		i--;
	}
	index->tab_e = (char **)malloc(sizeof(char *) * (id->c + 1));
	j = 0;
	i = id->d;
	while (i >= 0)
	{
		index->tab_e[j] = temp[j];
		j++;
		i--;
	}
	free(temp);
	index->tab_e[j] = NULL;
}
