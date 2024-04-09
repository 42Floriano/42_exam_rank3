/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_solo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:11:38 by albertini         #+#    #+#             */
/*   Updated: 2024/04/09 11:39:28 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif 

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

char	*ft_strdup(char *str)
{
	char *new = malloc(sizeof(char) * (ft_strlen(str) + 1));

	if (!new)
		return (NULL);
	ft_strcopy(new, str);
	return (new);
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
	free(strone);
	return (new);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int		to_copy = 0;
	int		countread = 0;
	
	line = ft_strdup(buf);
	while (!(newline = ft_strchr('\n', line))
			&& (countread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strcopy(buf, newline + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buf[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}
