/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_solo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:11:38 by albertini         #+#    #+#             */
/*   Updated: 2024/04/09 10:40:19 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_solo.h"

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char *new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	int i = 0;

	if (!new)
		return (NULL);
	ft_strcopy(new, str);
	return (new);
}

void	ft_strcopy(char *dst, char *src)
{
	int i = 0;

	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*ft_strjoin(char *strone, char *strtwo)
{
	char *new = malloc(sizeof(char) * (ft_strlen(strone) + ft_strlen(strtwo) + 1));
	int i = 0;
	int y = 0;
	
	if (!strone || !strtwo || !new)
		return (NULL);
	while (strone[i])
	{
		new [i] = strone[i];
		i++;
	}
	while (strtwo[y])
	{
		new[i++] = strtwo[y++];
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int		to_read = 0;
	int		countreaded = 0;
	
	line = ft_strdup(buf);
	while(!(newline = ft_strchr('\n', buf)) && )
	while(!())
	return (line);
}