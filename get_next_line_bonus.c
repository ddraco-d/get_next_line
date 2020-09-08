/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:44:59 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/18 13:45:00 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*rem_ch(char **rem, char **line)
{
	char			*p;

	p = NULL;
	if (*rem)
	{
		if ((p = ft_strchr(*rem, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(*rem);
			p++;
			ft_strcpy(*rem, p);
		}
		else
		{
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p);
}

char				*valid(char **line, size_t size, int fd)
{
	char			*buf;

	buf = NULL;
	if (size < 1 || fd < 0 || !line)
		return (NULL);
	if (!(buf = (char*)malloc(size + 1)))
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	else
		return (buf);
}

int					get_line(int fd, char **line, char **rem)
{
	int				was_read;
	char			*buf;
	char			*p;
	char			*tmp;

	if (!(buf = valid(line, BUFFER_SIZE, fd)))
		return (-1);
	p = rem_ch(rem, line);
	while (!p && (was_read = (int)read(fd, buf, BUFFER_SIZE)))
	{
		buf[was_read] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			free(*rem);
			*rem = ft_strdup(++p);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || was_read < 0)
			return (-1);
		free(tmp);
	}
	free(buf);
	return (p) ? 1 : 0;
}

t_list				*new(int fd)
{
	t_list			*p;

	if ((p = (t_list*)malloc(sizeof(t_list))))
	{
		p->fd = fd;
		p->next = NULL;
		p->rem = NULL;
	}
	return (p);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*tmp;

	if (head == NULL)
		head = new(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->rem));
}
