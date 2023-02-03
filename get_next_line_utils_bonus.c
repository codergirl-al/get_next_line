/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:42:56 by apeposhi          #+#    #+#             */
/*   Updated: 2023/02/03 16:48:07 by apeposhi         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	len;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		else
		{
			res[i] = s2[j];
			j++;
		}
		i++;
	}
	return (res);
}

/*
** @brief Cut a substring out of a given string by its starting index
** and length. Th substring is stored in a new memory address. The
** original string is left untouched.
**
** @param str:     a NULL-terminated string to cut the string from.
** @paarm start:   the starting index to cut from the string
** @param max_len: the maximum length to cut from the string
** @return the newly created substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s || start < 0)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
