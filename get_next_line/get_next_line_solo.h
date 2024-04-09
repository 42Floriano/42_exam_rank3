/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_solo.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:07:00 by albertini         #+#    #+#             */
/*   Updated: 2024/04/09 10:12:14 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_SOLO_H
# define GET_NEXT_LINE_SOLO_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif 

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif