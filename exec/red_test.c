/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:17:53 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/05 22:17:55 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av)
{
    char *str;
    int fd = open("file6", O_CREAT | O_RDWR, 0777);
    str = readline("");
    int a = strlen(str);
    write(fd, str, a);
}