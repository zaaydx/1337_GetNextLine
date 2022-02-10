/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:38:12 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/05 16:37:54 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlenbonus(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchrbonus(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlenbonus(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoinbonus(char *str1, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str2;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !buff)
		return (NULL);
	str2 = malloc(((ft_strlenbonus(str1) + ft_strlenbonus(buff)) + 1));
	if (str1 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			str2[i] = str1[i];
	while (buff[j] != '\0')
		str2[i++] = buff[j++];
	str2[ft_strlenbonus(str1) + ft_strlenbonus(buff)] = '\0';
	free(str1);
	return (str2);
}
