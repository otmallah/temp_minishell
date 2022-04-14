/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:53:35 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/28 10:53:37 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    ft_env(t_mini *index, t_list *list)
{
    int i;

    i = 0;
    list = ft_lstnew(index->tab_exp[i]);
    i += 1;
    while (index->tab_exp[i])
    {
        ft_lstadd_back(&list, ft_lstnew(index->tab_exp[i]));
        i++;
    }
}