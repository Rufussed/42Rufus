/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/08/28 18:47:37 by rlane            ###   ########.fr       */
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
// For pthread_create, pthread_join
# include <pthread.h>
// For gettimeofday
# include <sys/time.h>
// for processes
# include <semaphore.h>
// For O_* constants
# include <fcntl.h>
// For mode constants
# include <sys/stat.h>
// For waitpid
# include <sys/wait.h>
// For kill
# include <signal.h>

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
	int					eaten_enough;
	long long			last_eat;
	pthread_mutex_t		philo_mutex;
	pthread_t			check_starvation_thread;
	t_data				*data;
	pid_t				pid;
}	t_philo;

typedef struct s_data
{
	int					num_p;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					max_eat;
	int					end_sim;
	int					philos_full;
	pthread_mutex_t		end_sim_mutex;
	pthread_mutex_t		philo_full_mutex;
	pthread_t			check_end_sim_thread;
	pthread_t			philos_full_thread;
	sem_t				*end_sim_sem;
	sem_t				*philo_full_sem;
	sem_t				*forks_sem;
	sem_t				*waiter_sem;
	t_philo				*philos;
}	t_data;

int				ft_atoi(const char *nptr);
int				check_bad_chars(char *str);
int				init_philos(t_data *data);
t_data			*init_data(int argc, char **argv);
int				init_check_end_sim_thread(t_data *data);
void			free_data(t_data *data);
long long		get_time(void);
void			*philo_routine(void *arg);
int				exit_error_zero(char *msg);
char			*assign_colour(int id);
void			*philo_routine(void *arg);
void			print_status(t_philo *philo, char *msg);
void			pick_up_forks(t_philo *philo);
void			eat(t_philo *philo);
int				eaten_enough(t_philo *philo);
void			*check_end_sim_sem(void *arg);
int				check_end_sim(t_philo *philo);
void			close_semaphores(t_data *data);
int				check_end_sim_data(t_data *data);
void			*check_end_sim_sem(void *arg);
void			finish_threads_join(t_data *data);
void			*check_starvation(void *arg);

#endif