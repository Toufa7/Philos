/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:43 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:44 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_routine(t_philo *philo)
{
	ft_grab_fork(philo);
	ft_eat(philo);
	ft_release_fork(philo);
	ft_sleep(philo);
	ft_think(philo);
}
