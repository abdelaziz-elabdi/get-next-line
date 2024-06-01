/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:26:25 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/06/01 10:56:07 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(char *str_line, int fd)
{
	ssize_t	a;
	char	*buffer;

	a = 1;
	buffer = malloc(((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(str_line), NULL);
	buffer[0] = '\0';
	while (search_new_line(buffer, '\n') == 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (free(str_line), str_line = NULL, NULL);
		}
		if (!a)
			break ;
		buffer[a] = '\0';
		str_line = ft_strjoin(str_line, buffer);
	}
	free(buffer);
	return (str_line);
}

static char	*ft_line(char *str_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!str_line)
		return (0);
	while (str_line[i] != '\0' && str_line[i] != '\n')
		i++;
	if (str_line[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(str_line), NULL);
	i = 0;
	while (str_line[i] != '\0' && str_line[i] != '\n')
	{
		line[i] = str_line[i];
		i++;
	}
	if (str_line[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_rest_line(char *str_line)
{
	int		i;
	int		j;
	char	*rest_line;

	i = 0;
	j = 0;
	while (str_line[i] != '\0' && str_line[i] != '\n')
		i++;
	if (!str_line[i] || !str_line[i + 1])
		return (free(str_line), str_line = NULL, NULL);
	rest_line = malloc(ft_strlen(str_line) - i);
	if (!rest_line)
		return (free(str_line), NULL);
	i++;
	while (str_line[i] != '\0')
	{
		rest_line[j] = str_line[i];
		i++;
		j++;
	}
	rest_line[j] = '\0';
	free(str_line);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	static char	*str_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (free(str_line), str_line = NULL, NULL);
	str_line = ft_read(str_line, fd);
	if (!str_line)
		return (str_line = NULL, NULL);
	line = ft_line(str_line);
	if (!line)
		return (str_line = NULL, NULL);
	str_line = ft_rest_line(str_line);
	return (line);
}
