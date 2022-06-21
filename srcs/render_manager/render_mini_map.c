/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/21 14:42:58 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	render_wall(t_data *data, t_map *map, int x, int y);

void	render_mini_map(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->map.hgt)
	{
		x = -1;
		while (++x < (int)ft_strlen(data->map.tab[y]))
		{
			if (data->map.tab[y][x] != '1')
				render_rect(data, &data->walls,
					(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0xFFFFFF});
			else
				render_wall(data, &data->map, x, y);
		}
	}
	render_player(data);
}

static void	render_wall(t_data *data, t_map *map, int x, int y)
{
	if (x > 0 && map->tab[y][x - 1] != '1')
		render_rect(data, &data->walls,
			(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
	if (x < (int)ft_strlen(map->tab[y]) && map->tab[y][x + 1] != '1')
		if (map->tab[y][x + 1] != '1' && map->tab[y][x + 1] != 0)
			render_rect(data, &data->walls,
				(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
	if (y > 0 && (int)ft_strlen(map->tab[y - 1]) >= (int)ft_strlen(map->tab[y]))
		if (map->tab[y - 1][x] != '1')
			render_rect(data, &data->walls,
				(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
	if (y < map->hgt && (int)ft_strlen(map->tab[y + 1]) >= x + 1)
		if (map->tab[y + 1][x] != '1')
			render_rect(data, &data->walls,
				(t_rect){(x * 7) + 10, (y * 7) + 10, 2, 2, 0x000000});
}

void	render_player(t_data *data)
{
	double	x;
	double	y;

	x = ((data->player.x / 64) * 7) + 8;
	y = ((data->player.y / 64) * 7) + 8;
	render_rect(data, &data->walls, (t_rect){x, y, 2, 2, 0xFFFF00});
}

void	render_background(t_data *data)
{
	t_rect	background;

	background.x = 0;
	background.y = 0;
	background.wdth = data->win.wdth - 1;
	background.hgt = data->win.hgt - 1;
	background.color = BLACK;
	render_rect(data, &data->mini_map, background);
}

void	render_walls_and_tiles(t_data *data, int x, int y)
{
	t_rect	cell;

	cell.x = x * data->map.cell_size;
	cell.y = y * data->map.cell_size;
	cell.wdth = data->map.cell_size - 1;
	cell.hgt = data->map.cell_size - 1;
	if (data->map.tab[y][x] == '1')
	{
		cell.color = PINK;
		render_rect(data, &data->mini_map, cell);
	}
	else
	{
		cell.color = WHITE;
		render_rect(data, &data->mini_map, cell);
	}
}
