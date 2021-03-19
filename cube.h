/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:42:13 by mbahstou          #+#    #+#             */
/*   Updated: 2021/02/08 21:00:43 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./minilibx-linux/mlx.h"

typedef	struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_play
{
	int		posx;
	int		posy;
	char	dir;
}				t_play;

typedef struct	s_data
{
	char 	*line;
	int 	fd;
	int		resx;
	int		resy;
	char	*pat_no;
	char	*pat_so;
	char	*pat_ea;
	char	*pat_we;
	char	*pat_s;
	char	*map;
	char	**matrix_map;
	char	**copy;
	t_color	*ceiling;
	t_color	*floor;
	t_play	*player;
}				t_data;

int		description_read(t_data *data);
void	ft_init(t_data *data);
void	resolution(t_data *data);
int		c_color(t_data *data);
int		f_color(t_data *data);
int		color_errors(t_data *data);
void	t_paths(t_data *data);
void	map_read(t_data *data);
void	map_to_matrix(t_data *data, int rows, int cols);
void	mem_map (t_data *data);
void	copy_map (t_data *data, int rows, int cols);
void	p_finder (t_data *data, int rows);
void	p_position (t_data *data, int i, int j);
int		check_map (t_data *data, int i, int j);
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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif