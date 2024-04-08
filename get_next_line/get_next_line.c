/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:31:07 by falberti          #+#    #+#             */
/*   Updated: 2024/04/08 18:06:34 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char c, char *str)
{
	int i = 0;

	while (str[i] || str[i] != c)
	{
		
		i++;
	}	
	return (NULL);
}

//done
void	*ft_strcopy(char *dst, char *src)
{
	int i = 0;

	while (src[i])
		dst[i] = src[i++];
	dst[i] = '\0';
}

//done
char	*ft_strdup(char *str)
{
	char *new;

	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcopy(new, str);
	return (new);
}

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

}
