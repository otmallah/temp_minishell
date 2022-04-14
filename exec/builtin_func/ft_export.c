/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:00:56 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/14 01:08:53 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_temp(char **tab, t_idx *id)
{
	int i;
	int a;

	i = 0;
	while (i <= id->d)
	{
		printf("declare -x %s\n", tab[i]);
		i++;
	}
}

int		find_in_env_dup(t_mini *index, int id, char *str)
{
	int a;
	int i;

	i = 0;
	a = find_value(str);
	if (a == 1)
	{
		index->string[id] = str;
		return (1); 
	}
	return (0);
}

void	ft_print(t_mini *index, char *str, t_idx *id)
{
	int i;
	int j;
	int a = 0;
	char **temp;
	char *str_2;
	char *str_3;

	i = 0;
	j = 0;
	while (index->string[i])
	{
		puts("***********************");
		if (str)
		{
			//puts("**-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
			str_2 = ft_substr(index->string[i], 0, find_len(index->string[i]));
			//printf("s2 = %s \n", str_2);
			if (ft_strcmp(str, str_2) == 0)
				a = 2;
			else
			{
				j = find_value(str);
				if (j == 1)
				{
					str_3 = ft_substr(str, 0, find_len(str));
					if (ft_strcmp(str_2, str_3) == 0)
					{
						find_in_env_dup(index, i, str);
						a = 2;
					}
				}		
			}
		}
		if (!str)
			printf("declare -x %s\n" ,index->string[i]);
		i++;
	}
	j = 0;
	if (str != NULL && a != 2)
	{
		id->c++;
		if (!index->tab_e)
		{
			index->tab_e = (char **)malloc(sizeof(char *) * (id->c + 1));
			index->tab_e[id->d] = str;
			index->tab_e[id->d + 1] = NULL;
		}
		else
		{
			j = find_duplicate(index, str, id);
			if (j == 0)
			{
				add_to_temp2(index, id);
				id->d++;
				index->tab_e[id->d] = str;
			}
		}
	}
	if (index->tab_e && !str)
		ft_print_temp(index->tab_e, id);
}

void	ft_print_export(t_mini *index, t_idx *id, char *str)
{
	int i;
	int a;
	char *temp = NULL;

	i = 0;
	//puts("**-*-*-*-*-*-*-*-*-*-*-*");
	while (index->string[i + 1] != NULL)
	{
		if (ft_strcmp(index->string[i], index->string[i + 1]) > 0)
		{
			temp = index->string[i];
			index->string[i] = index->string[i + 1];
			index->string[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	ft_print(index, str, id);
}

void	ft_export(t_mini *index, t_idx *id, char *str)
{
	int j;

	j = 0;
	if (str)
	{
		id->cnt = find_value(str);
		if (id->cnt == 1)
		{
			if (!index->env_tab)
			{
				id->b++;
				index->env_tab = (char **)malloc(sizeof(char *) * (id->b + 1));
				index->env_tab[id->a] = str;
				index->env_tab[id->a + 1] = NULL;
			}
			else
			{
				j = find_dup(index, id, str);
				if (j == 2)
				{
					id->b++;
					add_to_temp(index, id);
					id->a++;
					index->env_tab[id->a] = str;
				}
			}
		}
	}
	ft_print_export(index, id, str);
}
