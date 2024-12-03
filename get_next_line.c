/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:09 by roo               #+#    #+#             */
/*   Updated: 2024/12/03 18:05:25 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(char *buffer)
{
	int		i;
	char	*line;
	int		line_len;

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
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp_buffer;
	char		*line;
	ssize_t		readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		if (!buffer)
		{
			buffer = (char *)malloc(BUFFER_SIZE + 1);
			if (!buffer)
				return (NULL);
			readed = read(fd, buffer, BUFFER_SIZE);
		}
		else
			readed = read(fd, temp_buffer, BUFFER_SIZE);
			if (readed <= 0)
				break;
			buffer = ft_strjoin(buffer, temp_buffer);
			write(1, buffer, ft_strlen(buffer));
			if (!buffer)
				return (free(temp_buffer), NULL);
	}
	line = ft_find_line(buffer);
	return (free(temp_buffer), line);
}
#include <stdio.h>
int	main(void)
{
    char *line;
	int fd = open("pipa.txt", O_RDONLY);
	while((line = get_next_line(fd)))
    {
        //printf("%s", line);
        free(line);
    }
    close(fd);
	return (0);
}