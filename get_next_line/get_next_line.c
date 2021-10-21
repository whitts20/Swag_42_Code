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

char	*ft_strjoin(char *str, char *s2)
{
	char	*con;

	if (s2 == NULL)
		return (NULL);
	con = (char *)malloc(sizeof(con) * (ft_strlen(str) + ft_strlen(s2) + 1));
	if (con == NULL)
		return (NULL);
	ft_strlcpy(con, str, ft_strlen(str) + 1);
	ft_strlcat(con, s2, ft_strlen(str) + ft_strlen(s2) + 1);
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

char	*ft_strtrim(char *str, char c)
{
	int		i;
	char	*trim;

	i = 0;
	while (str[i] != c)
		i++;
	trim = (char *) malloc(sizeof(char) * i);
	while (str[i] != c)
	{
		trim[i] = str[i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_excess(char	*str, char c)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	j = 0;
	while (str[i] != c)
		i++;
	trim = (char *) malloc(sizeof(char) * (ft_strlen(str) - i));
	i++;
	while (str[i] != '\0')
	{
		trim[j] = str[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}

char	*get_next_line(int fd)
{
	int			rtn;
	char		*line;
	char		*buf;
	char		*eof;
	static char	*oflw;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (0);
	rtn = 1;
	line = oflw;
	if (ft_toolong(line) > 1)
	{
		oflw = ft_excess(line, '\n');
		line = ft_strtrim(line, '\n');
		return (line);
	}
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ft_strchr(line, '\n') == 0) && (ft_strchr(line, '\0') == 0) && (rtn > 0))
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (ft_toolong(buf) > 0)
		{
			printf("HELLO\n");
			oflw = ft_excess(buf, '\n');
			line = ft_strtrim(buf, '\n');
			return (line);
		}
		else
			line = ft_strjoin(line, buf);
	}
	if (ft_strchr(line, '\0') == 1)
	{
		eof = ft_excess(line, '\0');
		line = ft_strtrim(line, '\0');
	}
	return (line);
}
