/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashcode.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:48:26 by vchornyi          #+#    #+#             */
/*   Updated: 2018/03/01 17:48:27 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHCODE_H
# define HASHCODE_H

# include "libft.h"

typedef struct s_point	t_point;
typedef struct s_map	t_map;
typedef struct s_ride	t_ride;

struct      s_point
{
	int x;
	int y;
};

struct      s_map
{
	int rows;
	int columns;
	int vehicles;
	int num_rides;
	int bonus;
	int steps;
	t_ride *ride;
};

struct      s_ride
{
	int 	car_num;
	int 	ride_index;
	t_point *start_point;
	t_point *finish_point;
	t_point	*current_point;
	int		earliest_start;
	int		latest_finish;
	t_ride *next;
};

#endif
