/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:32:57 by mbahstou          #+#    #+#             */
/*   Updated: 2021/03/31 01:28:18 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_to_matrix(t_data *data)
{
	int i;
	int j;
	int z;

	i = 0;
	z = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			data->matrix_map[i][j] = data->map[z];
			j++;
			z++;
		}
		i++;
	}
}

void	mem_map (t_data *data)
{
	int i;
	int j;

	i = 0;
	data->rows = 1;
	while (data->map[i] != '\0')
	{
		j = 0;
		while (data->map[i] != '\n' && data->map[i] != '\0')
		{
			i++;
			j++;
		}
		if (j > data->cols)
			data->cols = j;
		if (data->map[i] == '\n')
			data->rows++;
		i++;
	}
	
	i = 0;
	if (!(data->matrix_map = (char**)malloc( data->rows * sizeof(char*))))
		printf("fail allocating memory");
	while (i < data->rows)
	{
		if (!(data->matrix_map[i] = (char*)malloc(data->cols * sizeof(char))))
			printf("fail allocating memory");
		i++;
	}
	map_to_matrix(data);
	map_errors(data);
}

void	map_read(t_data *data)
{
	data->map = ft_strjoin(data->line, "\n");
	while (get_next_line(data->fd, &data->line))
	{
		data->map = ft_strjoin(data->map, ft_strjoin(data->line, "\n"));
	}
	data->map = ft_strjoin(data->map, data->line);
	mem_map(data);
}