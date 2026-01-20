/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:03:29 by anasinda          #+#    #+#             */
/*   Updated: 2025/11/14 23:30:55 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(char *string)
{
	int		i;
	int		size;
	char	*ptr;

	size = ft_strlen(string);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_append(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*ptr;

	if (!stash)
		stash = ft_strdup("");
	if (!stash || !buffer)
		return (NULL);
	ptr = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buffer)) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[j])
		ptr[i++] = stash[j++];
	j = 0;
	while (buffer[j])
		ptr[i++] = buffer[j++];
	ptr[i] = '\0';
	free(stash);
	return (ptr);
}
