/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:45:15 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/18 13:45:16 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	while (*ss && *ss != (char)c)
		ss++;
	if (*ss == (char)c)
		return (ss);
	return (NULL);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	if (s2)
	{
		while (s1[i] != '\0')
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(rez = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		rez[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		rez[i + j] = s2[j];
		j++;
	}
	rez[i + j] = '\0';
	return (rez);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
