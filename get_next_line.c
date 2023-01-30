/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:43:02 by apeposhi          #+#    #+#             */
/*   Updated: 2023/01/30 17:30:57 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char **buff, char *read)
{
	//in  developeplopeleoplement
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
