/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:31:07 by falberti          #+#    #+#             */
/*   Updated: 2024/04/09 00:48:39 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 42

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

static void	*ft_strcopy(char *dst, char *src)
{
	int i = 0;

	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *str)
{
	char *new;

	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcopy(new, str);
	return (new);
}

//done
char	*ft_strjoin(char *strOne, char *strTwo)
{
	char *new = malloc(sizeof(char) * (ft_strlen(strOne) + ft_strlen(strTwo)) + 1);

	if (!strOne || !strTwo || !new)
		return (NULL);
	ft_strcopy(new, strOne);
	ft_strcopy((new + ft_strlen(strOne)), strTwo);
	free(strOne);
	return (new);
}

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int		countread;
	int		to_copy;

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

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc != 2) {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return 1;
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         return 1;
//     }

//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return 0;
// }
