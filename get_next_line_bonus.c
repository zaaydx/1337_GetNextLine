/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:57:27 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/05 16:33:55 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*readbufbonus(char *str, int fd)
{
	char	*buffer;
	int		byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	byte = 1;
	while (ft_strchrbonus(str, '\n') == NULL && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		str = ft_strjoinbonus(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*storelinebonus(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	if (line == NULL)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*deletelinebonus(char *str)
{
	char	*buff;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	buff = malloc(ft_strlenbonus(str) - i + 1);
	if (buff == NULL)
		return (NULL);
	i++;
	while (str[i])
		buff[j++] = str[i++];
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = readbufbonus(str[fd], fd);
	if (str[fd] == NULL)
		return (NULL);
	line = storelinebonus(str[fd]);
	str[fd] = deletelinebonus(str[fd]);
	return (line);
}
