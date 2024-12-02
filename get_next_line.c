/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:09 by roo               #+#    #+#             */
/*   Updated: 2024/12/02 16:16:18 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_find_n(char *buffer)
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
void ft_free_free(char *matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
char *get_next_line(int fd)
{
    static char *buffer;
    char *temp_buffer;
    char *line;
    ssize_t readed;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    readed = 1;
    while (readed > 0)
    {
        readed = read(fd, temp_buffer, BUFFER_SIZE);
        if (readed < 0)
        {
            return(free(temp_buffer), free(buffer), NULL);
        }
        temp_buffer[BUFFER_SIZE] = '\0';
        buffer = ft_strjoin(buffer, temp_buffer);
        if (!buffer)
        {
            return(free(temp_buffer), NULL);
        }
    }
    line = ft_find_n(buffer);
    return (line);
}
#include <stdio.h>
int main()
{}