/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:31:09 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/05 16:33:22 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*readbuf(char *str, int fd);
char	*storeline(char *str);
char	*deleteline(char *str);

#endif
