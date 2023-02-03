/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:42:49 by apeposhi          #+#    #+#             */
/*   Updated: 2023/02/03 16:47:51 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create(int pos, char **buff)
{
	char	*temp;
	char	*result;

	temp = NULL;
	if (pos <= 0)
	{
		if (**buff == '\0')
		{
			free(*buff);
			*buff = NULL;
			return (NULL);
		}
		result = *buff;
		*buff = NULL;
		return (result);
	}
	temp = ft_substr(*buff, pos, BUFFER_SIZE);
	result = *buff;
	result[pos] = 0;
	*buff = temp;
	return (result);
}

char	*get_line(int fd, char **buff, char *read_r)
{
	ssize_t	read_b;
	char	*temp;
	char	*new_line;

	new_line = ft_strchr(*buff, '\n');
	temp = NULL;
	read_b = read(fd, read_r, BUFFER_SIZE);
	if (read_b <= 0)
	{
		return (create(read_b, buff));
		read_r[read_b] = 0;
		temp = ft_strjoin(*buff, read_r);
		free_space(buff);
		*buff = temp;
		new_line = ft_strchr(*buff, '\n');
	}
	return (create(new_line - *buff + 1, buff));
}

void	free_space(char **ptr_to_free)
{
	if (*ptr_to_free != NULL)
	{
		free(*ptr_to_free);
		ptr_to_free = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char		*buff = NULL;
	char			*read;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > BUFFER_SIZE)
		return (NULL);
	read = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	res = get_line(fd, &buff, read);
	free_space(&read);
	return (res);
}
