/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:03:31 by anasinda          #+#    #+#             */
/*   Updated: 2025/11/14 23:27:04 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_strdup(char *string);
char		*ft_append(char *stash, char *buffer);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);

#endif