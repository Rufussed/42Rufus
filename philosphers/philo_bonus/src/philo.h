/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/07/17 12:24:03 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// For printf
# include <stdio.h>
// For malloc, free
# include <stdlib.h>
// For memset
# include <string.h>
// For usleep, write
# include <unistd.h>
// For gettimeofday
# include <sys/time.h>
// for processes
# include <semaphore.h>
// For O_* constants
# include <fcntl.h>
// For mode constants
# include <sys/stat.h>

# define RESET "\033[0m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define RED "\033[0;31m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define BROWN "\033[0;33m"
# define ORANGE "\033[1;33m"
# define BOLD_ORANGE "\033[1;31m"
# define CYAN "\033[0;36m"

# define RESET_CURSOR "\033[1G"
# define DELETE_LINE "\033[2K"

# define TRUE 1
# define FALSE 0

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					num_eat;
	long long			last_eat;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	int					num_p;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					max_eat;
	int					end_sim;
	sem_t 				*forks_sem;

	t_philo				*philos;
	
}	t_data;

int				init_philos(t_data *data);
t_data			*init_data(int argc, char **argv);
void			free_data(t_data *data);
void			print_philos(t_data *data);
long long		get_time(void);
void			*philo_routine(void *arg);
int				join_philos(t_data *data);
int				exit_error_zero(char *msg);
char			*assign_colour(int id);
void			*philo_routine(void *arg);
void			print_status(t_philo *philo, char *msg);
void			pick_up_forks(t_philo *philo);
void			eat(t_philo *philo);
void			bedtime(t_philo *philo);
int				join_threads(t_data *data);
int				init_death_watch(t_data *data);
int				eaten_enough(t_philo *philo);
int				all_eaten_enough(t_data *data);
int				check_end_sim(t_data *data);

#endif