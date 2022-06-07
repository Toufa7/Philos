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
	philo->table->last_time_eat = ft_get_time(philo->table->start_time);
	printf("-------> Philo %d Last Time Eat -> %d <-------\n", philo->id, philo->table->last_time_eat);
	pthread_mutex_unlock(&philo->table->state_msg);
	ft_usleep(philo->table->time_eat);
}
