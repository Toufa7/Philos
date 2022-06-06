#include "philosophers.h"

int	ft_is_dead(t_philo *philo)
{
	int	diffrence;

	diffrence = ft_get_time(philo->table->start_time) - philo->table->last_time_eat;
	printf("Checking -> %d\n",diffrence);
	printf("Time to die -> %d\n",philo->table->time_die);
	if (diffrence > philo->table->time_die)
	{
		printf("Dead\n");
		return (1);
	}
	else
	{
		printf("Alive\n");
		return (0);
	}
}