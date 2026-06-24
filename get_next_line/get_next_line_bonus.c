/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:13:34 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/24 20:07:51 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;

	buffer = NULL;
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(stash), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(buffer);
		free(stash);
		if (!tmp)
			return (NULL);
		stash = tmp;
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static t_list	*stash_list;
	t_list		*node;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_node(stash_list, fd);
	if (!node)
	{
		node = new_node(fd);
		if (!node)
			return (NULL);
		node->next = stash_list;
		stash_list = node;
	}
	node->stash = read_and_stash(fd, node->stash);
	if (!node->stash || !node->stash[0])
	{
		free(node->stash);
		node->stash = NULL;
		return (delete_node(&stash_list, fd), NULL);
	}
	line = extract_line(node->stash);
	node->stash = update_stash(node->stash);
	return (line);
}
