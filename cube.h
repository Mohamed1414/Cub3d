/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:42:13 by mbahstou          #+#    #+#             */
/*   Updated: 2020/11/25 17:23:54 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_data
{
	char 	*line;
	int 	fd;
	char	*map;
	int		resx;
	int		resy;
	char	*pat_no;
	char	*pat_so;
	char	*pat_ea;
	char	*pat_we;
	char	*pat_s;
	t_color	*roof;
	t_color	*floor;
}				t_data;



void	map_read(t_data *data);
void	ft_init(t_data *data);
/*
**              				GET NEXT LINE
*/
int		get_next_line(int fd, char **line);
int		ft_finder(char **p, char **line);
char	*ft_remove(char *p, int len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);


/*
**									LIBFT
*/

int		ft_atoi(const char *str);
#endif