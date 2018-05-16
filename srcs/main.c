/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:32:55 by vchornyi          #+#    #+#             */
/*   Updated: 2018/03/01 17:32:58 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode.h"

t_ride *new_ride()
{
	t_ride *ride;
	ride = (t_ride*)malloc(sizeof(t_ride));
	ride->start_point = (t_point*)malloc(sizeof(t_point));
	ride->finish_point = (t_point*)malloc(sizeof(t_point));
	ride->current_point = (t_point*)malloc(sizeof(t_point));
	ride->car_num = 0;
	ride->next = NULL;
	return(ride);
}
t_map 	*reader(int fd)
{
	char 	*line;
	int 	i;
	int		finish;
	char 	**str;
	t_ride *tmp;
	t_map *map;
	t_ride *ride;
	t_point *start_point;
	t_point *finish_point;
	t_point *current_point;

	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	get_next_line(fd,&line);
	str = ft_strsplit(line, ' ');
	map->rows = ft_atoi(str[0]);
	map->columns = ft_atoi (str[1]);
	map->vehicles = ft_atoi (str[2]);
	map-> num_rides = ft_atoi (str[3]);
	map->bonus = ft_atoi(str[4]);
	map->steps = ft_atoi(str[5]);
	map->ride = new_ride();
	tmp = map->ride;
	while(finish = get_next_line(fd,&line))
	{
		tmp->ride_index = i;
		str = ft_strsplit(line, ' ');
		tmp->start_point->x = ft_atoi(str[0]);
		tmp->start_point->y = ft_atoi(str[1]);
		tmp->finish_point->x = ft_atoi(str[2]);
		tmp->finish_point->y = ft_atoi(str[3]);
		tmp->current_point->x = 0;
		tmp->current_point->y = 0;
		tmp->earliest_start = ft_atoi(str[4]);
		tmp->latest_finish = ft_atoi(str[5]);
		if (finish)
		{
			tmp->next = new_ride();
			tmp = tmp->next;
		}
		else
			tmp = NULL;
		i++;
	}
	return(map);
}

void	kick_last_elem(t_map **map)
{
	t_ride *tmp;
	t_ride *previous;

	tmp = (*map)->ride;
	while(tmp->next)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	previous->next = NULL;
}

int		main(int argc, char **argv)
{
	int fd;
	t_map *map;
	fd = open(argv[1],O_RDONLY);
	map = reader(fd);
	kick_last_elem(&map);
	ft_printf("TEST\n");
	return (0);
}