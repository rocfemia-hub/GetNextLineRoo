/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocfemia <rocfemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:56:42 by roo               #+#    #+#             */
/*   Updated: 2024/12/12 22:06:11 by rocfemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(char *buffer)
{
	int			i;
	char		*line;
	static int	line_len = 0;

	buffer = buffer + line_len;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	if (ft_strchr(buffer, '\n'))
		line_len = line_len + ft_strchr(buffer, '\n') - buffer + 1;
	else
		line_len = line_len + ft_strchr(buffer, '\0') - buffer;
	if (ft_strchr(buffer, '\n'))
		line = ft_calloc(sizeof(char), ft_strchr(buffer, '\n') - buffer + 2);
	else
		line = ft_calloc(sizeof(char), ft_strchr(buffer, '\0') - buffer + 1);
	if (line == NULL)
		return (NULL);
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
	static char		*buffer;
	char			*temp_buffer;
	char			*line;
	static ssize_t	readed = 1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (readed > 0)
	{
		temp_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (temp_buffer == NULL)
			return (free(buffer), NULL);
		readed = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp_buffer);
		free(temp_buffer);
	}
	line = ft_find_line(buffer);
	if ((readed == -1 && line == NULL && !buffer) || (readed == 0 && !line
			&& buffer))
		return (free(buffer), buffer = NULL, line);
	return (line);
}

/* int	main (int argc, char **argv)
{
	int a;
	char *str;

	if (argc < 2)
		return (1);
	a = open(argv[1], O_RDONLY);

	while((str = get_next_line(a)) != NULL)
	{
		printf("[%s]", str);
		if (!str)
			return (0);
		free(str);
	}
	free(str);
	close(a);
	return (0);
} */