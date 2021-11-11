/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:05:26 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/20 17:05:26 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*con;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (NULL);
	con = (char *)malloc(sizeof(con) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (con == NULL)
		return (NULL);
	while ((s1[i] != '\0') && (s1 != NULL))
	{
		con[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		con[i + j] = s2[j];
		j++;
	}
	con[i + j] = '\0';
	free (s1);
	return (con);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if ((s[i] == '\0') && (c == '\0'))
		return (1);
	return (0);
}

char	*ft_read(char *line, char *buf, int fd)
{
	int	rtn;

	rtn = 1;
	while ((ft_strchr(line, '\n') == 0) && (rtn != 0))
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		if (rtn < 0)
		{
			free(line);
			return (NULL);
		}
		buf[rtn] = '\0';
		line = ft_append(line, buf);
	}
	return (line);
}

char	*ft_intl(char *oflw, int fd, int check)
{
	char	*buf;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (oflw != NULL)
		line = ft_strdup(oflw);
	else if (oflw == NULL && check == 1)
		return (NULL);
	else
		line = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (buf == NULL)
		return (NULL);
	line = ft_read(line, buf, fd);
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*oflw;
	static int	check = 0;

	line = ft_intl(oflw, fd, check);
	free(oflw);
	if (ft_strchr(line, '\n') == 1)
	{
		oflw = ft_excess(line, '\n');
		buf = ft_strtrim(line, '\n');
		free(line);
		line = ft_strdup(buf);
		free(buf);
	}
	else if (ft_strchr(line, '\0') == 1)
	{
		if (line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
		buf = ft_strdup(line);
		free(line);
		line = ft_strtrim(buf, '\0');
		check = 1;
		free(buf);
		oflw = NULL;
	}
	return (line);
}
