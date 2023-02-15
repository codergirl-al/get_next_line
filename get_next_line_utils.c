/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:43:00 by apeposhi          #+#    #+#             */
/*   Updated: 2023/02/15 14:54:51 by apeposhi         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *) s + i);
		i++;
	}
	if (cc == s[i])
		return ((char *) s + i);
	return (NULL);
}
