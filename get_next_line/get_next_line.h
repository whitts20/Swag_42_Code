/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwhitfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:05:31 by rwhitfor          #+#    #+#             */
/*   Updated: 2021/10/20 17:05:31 by rwhitfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_excess(char	*str, char c);
char	*ft_strtrim(char *s1, char *set);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcat(char *dst, char *src, int dstsize);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlen(char *str);

#endif
