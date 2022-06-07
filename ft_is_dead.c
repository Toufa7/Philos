/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:51:12 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/06 13:04:48 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_dead(t_philo *philo)
{
	int	diffrence;

	diffrence = ft_get_time(philo->table->start_time) - philo->table->last_time_eat;
	printf("The Diffrence between last time eat and Now -> %d\n", diffrence);
	if (diffrence > philo->table->time_die)
	{
		pthread_mutex_lock(&philo->table->state_msg);
		printf("Philo %d is Dead\n", philo->id);
		return (1);
		pthread_mutex_unlock(&philo->table->state_msg);
	}
	else
	{
		printf("Philo %d still Alive\n", philo->id);
		return (0);
	}
}
