/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rideriction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 03:57:57 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/13 22:00:27 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection *init_redirection(char *val, t_type type)
{
	t_redirection *redirection;

	redirection = (t_redirection *)malloc(sizeof(t_redirection));
	redirection->file = ft_strdup(val);
	redirection->type = type;
	redirection->next = NULL;
	
	return (redirection);
}

void	add_redirecion(t_redirection *head, char *val, t_type type)
{
	t_redirection *current;
	t_redirection *new;

	if (head == NULL)
		exit(10);
	current = head;

	//while (current->next)
	//	current = current->next;
	while (current)
		current = current->next;
	new = (t_redirection *)malloc(sizeof(t_redirection));
	new->file = ft_strdup(val);
	new->type = type;
	new->next = NULL;
	current->next = new;
}