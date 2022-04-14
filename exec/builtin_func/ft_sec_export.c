/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sec_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:17:56 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/21 17:17:58 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print(t_list *list)
{
	while (list != NULL)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}

void    ft_print_export(char *str, t_mini *index)
{
	int i;
	int a;
	char *temp = NULL;

	i = 0;
	while (index->tab_exp[i + 1] != NULL)
	{
		if (ft_strcmp(index->tab_exp[i], index->tab_exp[i + 1]) > 0)
		{
			temp = index->tab_exp[i];
			index->tab_exp[i] = index->tab_exp[i + 1];
			index->tab_exp[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

t_list	*add_to_list(t_list *list, t_mini *index)
{
	int i;

	i = 0;
	list = ft_lstnew(index->tab_exp[i]);
	i += 1;
	while (index->tab_exp[i])
	{
		ft_lstadd_back(list, ft_lstnew(index->tab_exp[i]));
		i++;
	}
}

void	ft_export(t_mini *index, t_list *list, char *str)
{
	ft_print_export(str, index);
	list = add_to_list(list, index);
	if (!str)
		ft_print(list);
	else
	{
		ft_lstadd_back(list, ft_lstnew(str));
	}
}
