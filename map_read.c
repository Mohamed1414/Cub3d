/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:37:06 by mbahstou          #+#    #+#             */
/*   Updated: 2020/11/25 17:35:22 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_read(t_data *data)
{
	int i;
	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		if (data->line[i] == 'R' && data->line[i + 1] == ' ')
		{
			i++;
			while (data->line[i] != '\0')
			{
				if (data->resx == 0)
				{
					data->resx = ft_atoi(&data->line[i]);
					printf("%d", data->resx);
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
		/*else if (data->line[i] == 'N' && data->line[i + 1] == 'O'
			&& data->line[i + 2] == ' ')
		{
			i += 2;
			while (data->line[i] == ' ')
				i++;
			data->pat_no = ft_strdup(&data->line[i]);
		}
		else if (data->line[i] == 'S' && data->line[i + 1] == 'O'
			&& data->line[i + 2] == ' ')
		{
			i += 2;
			while (data->line[i] == ' ')
				i++;
			data->pat_so = ft_strdup(&data->line[i]);
		}
		else if (data->line[i] == 'W' && data->line[i + 1] == 'E'
			&& data->line[i + 2] == ' ')
		{
			i += 2;
			while (data->line[i] == ' ')
				i++;
			data->pat_we = ft_strdup(&data->line[i]);
		}
		else if (data->line[i] == 'E' && data->line[i + 1] == 'A'
			&& data->line[i + 2] == ' ')
		{
			i += 2;
			while (data->line[i] == ' ')
				i++;
			data->pat_ea = ft_strdup(&data->line[i]);
		}
		else if (data->line[i] == 'S' && data->line[i + 1] == ' ')
		{
			i++;
			while (data->line[i] == ' ')
				i++;
			data->pat_s = ft_strdup(&data->line[i]);
		}*/
	}
}
