/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:25:43 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/25 18:11:22 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_x(t_list *lst)
{
	t_list	*tmp;
	size_t	max_length;

	max_length = 0;
	tmp = lst;
	while (tmp)
	{
		if (ft_strlen(tmp->str) > max_length)
			max_length = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (max_length);
}

int	get_y(t_list *lst)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = lst;
	while (tmp)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

t_tile	**init_map(t_list *lst, t_data *data)
{
	t_tile	**new_map;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	data->map_x = get_max_x(lst);
	data->map_y = get_y(lst);
	new_map = (t_tile **)malloc(sizeof(t_tile *) * data->map_y);
	if (!new_map)
		ft_error(data, "Failed to allocate map", 1);
	while (i < data->map_y)
	{
		new_map[i] = (t_tile *)malloc(sizeof(t_tile) * data->map_x);
		if (!new_map[i])
			ft_error(data, "Failed to allocate map tiles", 1);
		while (j < data->map_x)
			new_map[i][j++] = SPACE;
		j = 0;
		i++;
	}
	return (new_map);
}

void	process_tile(char c, t_tile *tile)
{
	if (c == ' ')
		*tile = SPACE;
	else if (c == '1')
		*tile = WALL;
	else if (c == '0')
		*tile = EMPTY;
	else if (c == 'N')
		*tile = NORTH;
	else if (c == 'S')
		*tile = SOUTH;
	else if (c == 'E')
		*tile = EAST;
	else if (c == 'W')
		*tile = WEST;		
}

t_tile	**parse_list_to_array(t_list *lst, t_data *data)
{
	t_tile	**map;
	t_list	*tmp;
	int		x;
	int		y;

	map = init_map(lst, data);
	tmp = lst;
	x = 0;
	y = 0;
	while(tmp)
	{
		while (tmp->str[x])
		{
			process_tile(tmp->str[x], &map[y][x]);

			x++;
		}
		x = 0;
		y++;
		tmp = tmp->next;
	}

	return (map);
}