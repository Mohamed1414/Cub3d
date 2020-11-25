/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:37:06 by mbahstou          #+#    #+#             */
/*   Updated: 2020/11/25 19:31:16 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	resolution(t_data *data)
{
	int i;

	i = 2;
	while (data->line[i] != '\0')
	{
		if (data->resx == 0)
		{
			data->resx = ft_atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else if (data->resy == 0)
		{
			data->resy = ft_atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else
			break ;
	}
}

int	c_color(t_data *data)
{
	int i;

	i = 2;
	while (data->line[i] != '\0')
		if (!((data->line[i] > 47 && data->line[i] < 58)
		|| data->line[i] == ','))
		{
			printf("%s", "tu vieja");
			return (1);
		}
	while (data->line[i] != '\0')
	{
		data->ceiling->r = ft_atoi(&data->line[i]);
		while (data->line[i] != ',')
			i++;
		data->ceiling->g = ft_atoi(&data->line[i + 1]);
		i++;
		while (data->line[i] != ',')
			i++;
		data->ceiling->b = ft_atoi(&data->line[i + 1]);
		break ;
	}
	return (0);
}

int		map_read(t_data *data)
{
	int i;

	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		if (data->line[i] == 'R' && data->line[i + 1] == ' ')
			resolution(data);
		else if (data->line[i] == 'C' && data->line[i + 1 == ' '])
			if (c_color(data) == 1)
				return(1);
		else if (data->line[i] == 'F' && data->line[i + 1 == ' '])
			f_color(data);
	}
}
