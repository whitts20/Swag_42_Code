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

char	*get_next_line(int fd)
{
	int			rtn;
	char		*line;
	char		*buf;
	char		*tmp;
	static char	*oflw;
	static	int	check = 0;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rtn = 1;
	if (oflw != NULL)
	{
		line = ft_strdup(oflw);
		if (ft_strchr(line, '\n') == 1)
		{
			oflw = ft_excess(line, '\n');
			tmp = ft_strtrim(line, '\n');
			free(line);
			line = ft_strdup(tmp);
			free(tmp);
			return (line);
		}
	}
	else if (oflw == NULL && check == 1)
		return (NULL);
	else
		line = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while ((ft_strchr(line, '\n') == 0) && (rtn != 0))
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		if (rtn < 0)
		{
			free(line);
			free(buf);
			return (NULL);
		}
		buf[rtn] = '\0';
		if (ft_strchr(buf, '\n') == 1)
		{
			free(oflw);
			free(line);
			oflw = ft_excess(buf, '\n');
			line = ft_strtrim(buf, '\n');
			free(buf);
			return (line);
		}
		else
		{
			tmp = ft_strdup(line);
			free(line);
			line = ft_strjoin(tmp, buf);
			free(tmp);
		}
	}
	if (ft_strchr(line, '\0') == 1)
	{
		if (line[0] == '\0')
		{
			free(line);
			free(buf);
			free(oflw);
			return (NULL);
		}
		free(buf);
		buf = ft_strdup(line);
		line = ft_strtrim(buf, '\0');
		check = 1;
		free(oflw);
		free(buf);
		oflw = NULL;
	}
	return (line);
}
