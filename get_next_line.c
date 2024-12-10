/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:56:42 by roo               #+#    #+#             */
/*   Updated: 2024/12/10 14:48:33 by roo              ###   ########.fr       */
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
    static char *buffer;
    char        *temp_buffer;
    char        *line;
    ssize_t     readed;
    unsigned int    aux;

    if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
    buffer = ft_calloc(1, BUFFER_SIZE + 1);
    readed = 1;
    while (readed > 0)
    {
        temp_buffer = ft_calloc(1, BUFFER_SIZE + 1);
        readed = read(fd, temp_buffer, BUFFER_SIZE);
        if (readed <= 0)
            break;
        buffer = ft_strjoin(buffer, temp_buffer);
        free(temp_buffer);
    }
    line = ft_find_line(buffer);
    aux = ft_strlen(line);
    buffer = ft_substr(buffer, aux, ft_strlen(buffer));
    printf("%s\n", buffer);
    return(line);
}
/*int main(void)
{
    char *buffer;
    int fd = open("patata.txt", O_RDONLY);
    buffer = get_next_line(fd);
    printf("%s\n", buffer);
    close(fd);
    free(buffer);
    return(0);
}*/
/*int main(void)
{
    char *line;
	int fd = open("patata.txt", O_RDONLY);
	while((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
	return (0);
}*/
#include <fcntl.h>
int main(void)
{
    char *line;
    int fd = open("patata.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return(0);
    
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    /* printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd)); */
}