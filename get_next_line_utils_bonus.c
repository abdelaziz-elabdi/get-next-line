/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:43:49 by ael-abdi          #+#    #+#             */
/*   Updated: 2023/12/28 18:00:19 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc(ft_strlen(s)+1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*d;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	d = (char *)malloc((ft_strlen(s1)+ft_strlen(s2)+1));
	if (!d)
		return (free(s1), NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		d[i] = s2[j];
		i++;
		j++;
	}
	d[i] = 0;
	free(s1);
	return (d);
}

int	search_new_line(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == d)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
