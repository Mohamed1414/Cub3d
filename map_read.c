/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:32:57 by mbahstou          #+#    #+#             */
/*   Updated: 2020/12/01 19:02:24 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_read(t_data *data)
{
	int i;

	data->map = ft_strjoin(data->line, "\n");
	while (get_next_line(data->fd, &data->line))
	{
		data->map = ft_strjoin(data->map, ft_strjoin(data->line, "\n"));
	}
	data->map = ft_strjoin(data->map, data->line);
}

void	map_to_matrix(t_data *data)
{

}