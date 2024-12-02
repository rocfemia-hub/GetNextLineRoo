/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:09 by roo               #+#    #+#             */
/*   Updated: 2024/12/02 19:59:09 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_find_line(char *buffer)
{
    int i;
    char *line;
    int line_len;

    if (ft_strchr(buffer, '\n'))
        line_len = ft_strchr(buffer, '\n') - buffer + 1;
    else
        line_len = ft_strchr(buffer, '\0') - buffer;
    line = malloc(line_len * sizeof(char));
    if (!line)
        return (free(line), NULL);
    i = 0;
    while (buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] == '\0';
    return (line);
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
    ssize_t read;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    temp_buffer = (char *)malloc(BUFFER_SIZE + 1)
    if(!temp_buffer)
        return(free(temp_buffer), NULL);
    read = 1;
    while (read > 0)
    {
        read = read(fd, temp_buffer, BUFFER_SIZE);
        if (read < 0)
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
    line = ft_find_line(buffer);
    return (line);
}
#include <stdio.h>
int main()
{
    int fd = open("pipa.txt", O_RDONLY);
    get_next_line(fd);
    return(0);
}