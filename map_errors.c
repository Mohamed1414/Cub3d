/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:54:05 by mbahstou           #+#    #+#             */
/*   Updated: 2021/01/25 12:54:06 by mbahstou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//comprueba si el mapa es valido ###crear funcion para gestionar los returns###
int check_map (t_data *data, int i, int j)
{
    if (data->copy[i][j] == '0')
    {
        data->copy[i][j] = '.';
        if (check_map(data, i, j + 1) || check_map(data, i, j - 1) ||
            check_map(data, i + 1, j) || check_map(data, i - 1, j))
                return (1);
        else
                return (0);
    }
    else if (data->copy[i][j] == '1' || data->copy[i][j] == '.')
        return (0);
    else if (data->copy[i][j] == ' ' || data->copy[i][j] == '\0')
        return (1);
    return (1);
}

//encuentra la posicion del jugador
void p_position (t_data *data, int i, int j)
{
    data->player->posx = i;
    data->player->posy = j;
    if (data->copy[i][j] == 'N')
        data->player->dir = 'N';
    if (data->copy[i][j] == 'S')
        data->player->dir = 'S';
    if (data->copy[i][j] == 'E')
        data->player->dir = 'E';
    if (data->copy[i][j] == 'W')
        data->player->dir = 'W';
    data->copy[i][j] == '0';
    check_map(data, i, j);
}

void p_finder (t_data *data, int rows)
{
    int i;
    int j;

    while (i < rows)
    {
        i = 0;
        while (data->copy[i][j] != '\0')
        {
            if (data->copy[i][j] == 'N' || data->copy[i][j] == 'S'
            || data->copy[i][j] == 'E' || data->copy[i][j] == 'W')
            {
                p_position(data, i, j);
            }
            else if (data->copy[i][j] == '2')
                data->copy[i][j] = '0';
            j++;
        }
        i++;
    }
}
//copia el mapa para hacer en la copia las comprobaciones
void copy_map (t_data *data, int rows, int cols)
{
    int i;
    int j;
    int z;

    i = 0;
    z = 0;
    if (!(data->copy = (char**)malloc( rows * sizeof(char*))))
		printf("fail allocating memory");
	while (i < rows)
	{
		if (!(data->copy[i] = (char*)malloc(cols * sizeof(char))))
			printf("fail allocating memory");
		i++;
	}
    i = 0;
    while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			data->matrix_map[i][j] = data->map[z];
			j++;
			z++;
		}
		i++;
	}
}