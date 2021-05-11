/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:11:39 by sbertali          #+#    #+#             */
/*   Updated: 2021/05/07 19:38:10 by sbertali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static int	outputs(int n, char **buff, char **line)
{
	char	*temp;

	if (n < 0)
		return (-1);
	*line = ft_substr(*buff, 0, ft_strclen(*buff, '\n'));
	if (!line)
		return (-1);
	if (ft_strchr(*buff, '\n'))
	{
		temp = ft_strdup(ft_strchr(*buff, '\n') + 1);
		ft_strdel(&*buff);
		*buff = temp;
		return (1);
	}
	ft_strdel(&*buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff_line[_SC_OPEN_MAX];
	char		*new_line;
	int			nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > RLIMIT_NOFILE || !line)
		return (-1);
	if (!(buff_line[fd]))
		buff_line[fd] = ft_strdup("");
	if (!buff_line[fd])
		return (-1);
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_line)
		return (-1);
	nbytes = read(fd, new_line, BUFFER_SIZE);
	while (nbytes > 0)
	{
		new_line[nbytes] = '\0';
		buff_line[fd] = ft_strjoin_free(buff_line[fd], new_line);
		if (ft_strchr(buff_line[fd], '\n'))
			break ;
	}
	ft_strdel(&new_line);
	return (outputs(nbytes, &buff_line[fd], line));
}
