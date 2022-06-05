/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:12 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:13 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->state_msg);
	printf("%lu %d is eating\n", ft_get_time(philo->table->start_time), philo->id);
	printf("Start Time -> %lu\n", philo->table->start_time);
	pthread_mutex_unlock(&philo->table->state_msg);
	ft_usleep(philo->table->time_eat);
}
