/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:05 by roo               #+#    #+#             */
/*   Updated: 2024/12/10 14:54:07 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	int		s3_len;
	char	*s3;

	i = 0;
	j = 0;
	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(s3_len * sizeof(char) + 1);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (free(s1), s3);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			nmemb_size;
	size_t			i;
	unsigned char	*aux_ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	nmemb_size = nmemb * size;
	aux_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb_size)
	{
		aux_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		result = malloc(sizeof(char) * (1));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
