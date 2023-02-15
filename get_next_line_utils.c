/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:43:00 by apeposhi          #+#    #+#             */
/*   Updated: 2023/02/15 14:59:51 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** @param str: a NULL-terminated string
** @return the length of the given string
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
** @brief Join two strings into a new memory. The second string
** is concatenated after the first string. It is equivalence
** to the "concat" function in other programming languages.
**
** @param s1: the 1st NULL-terminated string
** @param s2: the 2nd NULL-terminated string
** @return a new memory address storing the string after
** concatenation of the 2 original strings. NULL is returned if
** malloc fails.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	if (!s2)
		return (s1);
	res = (char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), res);
}

/*
** @brief Locate the first given char in a given string.
**
** @param str: a NULL-terminated string
** @param c:   the value to find in the string, it is interpreted
** as char during search.
** @return the memory address of the value in the string
*/
char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	f;

	ptr = (char *)s;
	i = 0;
	f = (unsigned char) c;
	while (s[i] != '\0')
	{
		if (s[i] == f)
			return (&(ptr[i]));
		i++;
	}
	if (f == '\0')
		return (&(ptr[i]));
	return (0);
}
