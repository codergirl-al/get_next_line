/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:46:40 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/09 18:10:35 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_read(char *s_buff)
{
	char	*str;
	int		i;

	if (!s_buff[0])
		return (NULL);
	i = 0;
	while (s_buff[i] != '\0' && s_buff[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
	{
		free(s_buff);
		return (NULL);
	}
	i = -1;
	while (s_buff[++i] && s_buff[i] != '\n')
		str[i] = s_buff[i];
	if (s_buff[i] == '\n')
		str[i++] = '\n';
	*(str + i) = '\0';
	return (str);
}

char	*ft_get_buff(char *s_buff)
{
	char	*str;
	int		i;
	int		c;

	i = 0;
	while (s_buff[i] && s_buff[i] != '\n')
		i++;
	if (!s_buff[i])
	{
		free(s_buff);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s_buff) - i + 1));
	if (!str)
	{
		free(s_buff);
		return (NULL);
	}
	i++;
	c = 0;
	while (s_buff[i])
		str[c++] = s_buff[i++];
	str[c] = '\0';
	free(s_buff);
	return (str);
}

char	*ft_get_buffer(int fd, char *s_buff)
{
	char	*t_buff;
	int		byte_r;
	int		fst;

	t_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!t_buff)
		return (NULL);
	byte_r = 1;
	fst = 1;
	while (fst || (!ft_strchr(t_buff, '\n') && byte_r))
	{
		fst = 0;
		byte_r = read(fd, t_buff, BUFFER_SIZE);
		if (byte_r == -1)
			return (free(t_buff), NULL);
		t_buff[byte_r] = '\0';
		s_buff = ft_strjoin(s_buff, t_buff);
	}
	return (free(t_buff), s_buff);
}

char	*get_next_line(int fd)
{
	static char		*static_buffer[OPEN_MAX];
	char			*read_l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, static_buffer[fd], 0) < 0)
	{
		if (static_buffer[fd])
		{
			free(static_buffer[fd]);
			static_buffer[fd] = NULL;
		}
		return (NULL);
	}
	static_buffer[fd] = ft_get_buffer(fd, static_buffer[fd]);
	if (!static_buffer[fd])
		return (NULL);
	read_l = ft_get_read(static_buffer[fd]);
	static_buffer[fd] = ft_get_buff(static_buffer[fd]);
	return (read_l);
}
