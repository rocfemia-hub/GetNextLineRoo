/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:09 by roo               #+#    #+#             */
/*   Updated: 2024/11/15 16:19:50 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_find_n(int fd, char *buffer)
{
    int i;
    char *str;

    i = 0;
    while (buffer[i] != '\n')
    {
        str[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        str[i] == '\n';
    else if
        return (NULL);
    return (str);
}
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }

    return (line);
}
#include <stdio.h>
int main()
{}