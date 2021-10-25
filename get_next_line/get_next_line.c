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
	static char	*oflw;
	
	if (fd <= 0 || BUFFER_SIZE < 1)
		return (0);
	rtn = 1;
	if (oflw != NULL)
	{
		line = ft_strdup(oflw);
		if (ft_strchr(line, '\n') == 1)
		{
			oflw = ft_excess(line, '\n');
			line = ft_strtrim(line, '\n');
			return (line);
		}
	}
	else
		line = ft_null();
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (((ft_strchr(line, '\n') == 0) || (ft_strchr(line, '\0') == 0)) && (rtn > 0))
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (ft_strchr(line, '\n') == 1)
		{
			oflw = ft_excess(line, '\n');
			line = ft_strtrim(buf, '\n');
			free(buf);
			return (line);
		}
		else
		{
			line = ft_strjoin(line, buf);
			free(buf);
		}
	}
	if (ft_strchr(line, '\0') == 1)
		line = ft_strtrim(line, '\0');
	return (line);
}
