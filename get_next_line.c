/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:03:26 by anasinda          #+#    #+#             */
/*   Updated: 2025/11/14 23:16:43 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_buffers(char *s1, char *s2, int sign)
{
	if (sign == 1)
		free(s1);
	if (sign == 2)
	{
		free(s1);
		free(s2);
	}
	return (NULL);
}

static char	*ft_check_next_line(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * ((ft_strlen(stash) - i) + 1));
	if (!temp)
		return (NULL);
	j = -1;
	while (stash[i + (++j)])
		temp[j] = stash[i + j];
	temp[j] = '\0';
	free(stash);
	stash = temp;
	return (stash);
}

static char	*ft_check_line(char *stash, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i + 2)
		line[j++] = '\0';
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_check_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	byte_count;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_count = 1;
	while (byte_count > 0)
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == -1)
			return (ft_free_buffers(buffer, NULL, 1));
		buffer[byte_count] = '\0';
		stash = ft_append(stash, buffer);
		if (stash[0] == '\0')
			return (ft_free_buffers(buffer, stash, 2));
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	stash = ft_check_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_check_line(stash, line);
	stash = ft_check_next_line(stash);
	return (line);
}
