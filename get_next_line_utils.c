/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:43:00 by apeposhi          #+#    #+#             */
/*   Updated: 2023/02/13 16:44:31 by apeposhi         ###   ########.fr       */
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
** @brief Duplicates a string to a new memory address.
**
** @param str: a NULL-terminated stirng
** @return the new string after duplication from the given string
*/


char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*s2;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	s2 = (char *) malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
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
	size_t	index;
	size_t	count;
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	result = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = -1;
	count = 0;
	if (s1)
		while (s1[++index] != '\0')
			result[index] = s1[index];
	while (s2[count] != '\0')
		result[index++] = s2[count++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (result);
}

/*
** @brief Safe copy of the source string to the destination 
** string. It only copies up to a maximum amount of char.
**
** @param dest: the destination memory address to copy to.
** @param src:  a NULL-terminated string to be copied from.
** @param max_len: the maximum length of char to be copied.
** @return the length of the destination string after copying.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size > 0)
	{
		while (src[n] && n < (size - 1))
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = 0;
	}
	while (src[n])
		n++;
	return (n);
}
