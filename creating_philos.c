/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:04 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:05 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (true)
	{
		ft_routine(philo);
	}
	return (NULL);
}

void	creating_philos(t_philo *philo, const char **av)
{
	int		idx;
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->start_time = ft_get_time(0);
	table->nbr_philo = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	idx = 0;
	ft_mutex_init(philo, table);
	while (idx < table->nbr_philo)
	{
		philo[idx].id = idx + 1;
		philo[idx].table = table;
		pthread_create(&philo[idx].thread, NULL, &philo_routine, &philo[idx]);
		usleep(100);
		idx++;
	}
	idx = 0;
	while (idx < table->nbr_philo)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
}
