/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:37:11 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/14 00:02:24 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "minishell_exec.h"


 char *ft_strdup(char *s);
int	isop(char c);
int ft_isspace(int c);
//int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void ft_putstr_fd(char *s, int fd);
#endif