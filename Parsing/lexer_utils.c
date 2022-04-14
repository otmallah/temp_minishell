/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:49:07 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/09 02:01:39 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isop(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' 
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->contents))
	{
		lexer->i++;
		lexer->c = lexer->contents[lexer->i];
	}
}
void lexer_retreat(t_lexer *lexer)
{
	if (lexer->i > 0)
	{
		lexer->i--;
		lexer->c = lexer->contents[lexer->i];
	}
}

t_lexer	*init_lexer(char *contents)
{
	t_lexer *lexer;
	

	lexer = calloc(1, sizeof(struct s_lexer));
	lexer->contents = contents;
	lexer->i = 0;
	lexer->c = contents[lexer->i];
	return lexer;
}