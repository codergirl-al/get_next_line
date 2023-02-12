/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:43:02 by apeposhi          #+#    #+#             */
/*   Updated: 2023/02/12 14:11:40 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	free_space(char *ptr_to_free)
{
	if (ptr_to_free != NULL)
		free(ptr_to_free);
}

char	*ft_get_read(char *s_buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!s_buff[0])
		return (NULL);
	while (s_buff[i] && s_buff[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s_buff[i] && s_buff[i] != '\n')
	{
		str[i] = s_buff[i];
		i++;
	}
	if (s_buff[i] == '\n')
	{
		str[i] = s_buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_buff(char *s_buff)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (s_buff[i] && s_buff[i] != '\n')
		i++;
	if (!s_buff[i])
	{
		free_space(s_buff);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s_buff) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (s_buff[i])
		str[c++] = s_buff[i++];
	str[c] = '\0';
	free_space(s_buff);
	return (str);
}

char	*ft_get_line_and_store_output(int fd, char **s_buff)
{
	char	*t_buff;
	int		byte_r;
	char	*tmp;

	t_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!t_buff)
		return (NULL);
	byte_r = 1;
	while (byte_r > 0)
	{
		byte_r = read(fd, t_buff, BUFFER_SIZE);
		t_buff[byte_r] = '\0';
		tmp = ft_strjoin(*s_buff, t_buff);
		free_space(*s_buff);
		*s_buff = tmp;
	}
	if (byte_r == -1)
	{
		free_space(t_buff);
		return (NULL);
	}
	free_space(t_buff);
	return (*s_buff);
}

char	*get_next_line(int fd)
{
	static char		*static_buffer;
	char			*read_l;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1024 || read(fd, static_buffer, 0) < 0)
	{
		free(static_buffer);
		return (static_buffer);
	}
	static_buffer = ft_get_line_and_store_output(fd, &static_buffer);
	if (!static_buffer)
		return (static_buffer);
	read_l = ft_get_read(static_buffer);
	static_buffer = ft_get_buff(static_buffer);
	return (read_l);
}

// int main()
// {
// 	int	fd;

// 	fd = open("empty.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
