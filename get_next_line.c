/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:56:42 by roo               #+#    #+#             */
/*   Updated: 2024/12/10 18:59:08 by roo              ###   ########.fr       */
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
	line = malloc(line_len * sizeof(char) + 1);
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
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
    static char     *buffer;
    char            *temp_buffer;
    char            *line;
    ssize_t         readed;
    unsigned int    aux;

    if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
    buffer = ft_calloc(1, BUFFER_SIZE + 1);
    readed = 1;
    while (readed > 0 && (!ft_strchr(buffer, '\n')))
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
    //printf("%s", buffer);
    return(line);
}

#include <fcntl.h>
/* int main(void)
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
} */
int	main (void)
{
 	char file[] = "./patata.txt";
 	int a;
 	char *str;
/* 
 	a = open(file, O_RDONLY);

 	if (BUFFER_SIZE > 100) {
 		char *temp;
 		do {
 			temp = get_next_line(a);

 			free(temp);
 		} while (temp != NULL);
 	}

 	close(a); */
 	a = open(file, O_RDONLY);

 	while((str = get_next_line(a)) != NULL)
 	{
 		printf("%s", str);
 		free(str);
 	}
 	free(str);
    
 	// printf("%s\n", get_next_line(a));
 	// printf("%s", get_next_line(a));
 	close(a);
	return (0);
}