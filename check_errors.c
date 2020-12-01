/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:34:47 by mbahstou          #+#    #+#             */
/*   Updated: 2020/11/27 17:55:41 by mbahstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	color_errors(t_data *data)
{
	int i;

	i = 2;
	while (data->line[i] != '\0')
	{
		if (!((data->line[i] > 47 && data->line[i] < 58)
		|| data->line[i] == ','))
		{
			printf("%s", "invalid set of colors");
			return (1);
		}
		i++;
	}
	return (0);
}
